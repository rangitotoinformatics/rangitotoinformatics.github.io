# Architecture

## Now: static site

```
GitHub repo (Markdown content) ──push──▶ GitHub Actions (astro build + pagefind) ──▶ GitHub Pages
```

- **Astro** renders every lesson and problem to static HTML at build time.
- **Content collections** (`src/content.config.ts`) validate frontmatter, so malformed content fails the build.
- **`src/lib/content.ts`** is the only module pages use to read content. Pages never call `getCollection` directly.
- **Pagefind** builds a search index at build time; search runs entirely in the browser. Problem and lesson pages expose `type`, `difficulty` and `topic` filters.
- **Problems list filters** (title, difficulty, topic) are plain client-side JS over the rendered list, synced to the URL (`/problems/?topic=binary%20search`).
- Students submit on the original judge via `submitUrl` (e.g. train.nzoi.org.nz) with their own accounts.

## Later: backend

Planned features: admins, online judge, progress and leaderboard, contests, problem of the week, usage analytics.

### Shape

```
Browser ──▶ Astro site (static, or SSR via an adapter)
   │
   ├──▶ API + auth + Postgres (Supabase, or a small API server)
   │        ▲
   │        │ verdicts
   └──▶ Submission queue ──▶ Judge workers (sandboxed: isolate / Docker, or Judge0)
                                  │
                                  └── hidden tests (private storage, not this repo)
```

### Data model (draft)

| Table | Key fields |
|---|---|
| `users` | id, name, role (`student` / `admin`) |
| `problems` | id (`P0001`…, same as frontmatter), slug, title, difficulty, topics, time/memory limits |
| `tests` | problem_id, index, input_path, output_path, subtask, points |
| `submissions` | id, user_id, problem_id, contest_id?, language, code, verdict, score, time_ms, memory_kb, created_at |
| `contests` | id, title, start, end |
| `contest_problems` | contest_id, problem_id, order |
| `problem_of_the_week` | week_start, problem_id |

Progress and leaderboards are queries over `submissions` (best score per user per problem), so they need no extra tables.

### Migration steps

1. **Accounts and progress.** Add Supabase auth from the browser; the site can stay static. Row-level security restricts admin actions to `role = 'admin'`.
2. **Sync problems.** A CI step upserts problem metadata from frontmatter into `problems`, keyed by `id`. The repo stays the source of truth for content.
3. **Judge.** Deploy judge workers on a VPS. Hidden tests live in private storage (a private repo synced by CI, or the judge's disk). The site posts submissions to the API and polls or subscribes for verdicts.
4. **Contests and problem of the week.** Rows in `contests` / `problem_of_the_week`, managed from an admin page.
5. **SSR only if needed.** If pages must render per-user data on the server, add an Astro adapter (e.g. `@astrojs/node` or `@astrojs/vercel`) and move hosting off GitHub Pages. With a custom domain, users won't notice the move.

### Why this is easy to migrate

- Problem IDs are permanent, so submissions and progress can reference them from day one.
- Pages only go through `src/lib/content.ts`, so switching a data source is a change in one place.
- Content stays in Markdown in git, which works with both static and server builds.
- Hidden tests are never in the public repo, so nothing has to be scrubbed later.
