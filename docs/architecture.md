# Architecture

## Folders

| Path | Purpose |
|---|---|
| `.github/workflows/` | CI: build and deploy to GitHub Pages |
| `docs/` | Design docs |
| `public/` | Static files served as-is (images, favicon) |
| `src/content/lessons/` | One Markdown file per lesson |
| `src/content/problems/` | One folder per problem: statement, editorial, model solution |
| `src/layouts/` | Shared page layouts |
| `src/components/` | Reusable UI pieces (e.g. tags) |
| `src/lib/` | Data-access layer: the only code that reads content |
| `src/pages/` | Routes |

## Phase 1: static site (GitHub Pages)

| Feature | Route |
|---|---|
| Homepage (about informatics and competitions) | `/` |
| Lessons | `/lessons/`, `/lessons/<slug>/` |
| Problems, editorials, model solutions | `/problems/`, `/problems/<slug>/` |
| Search and tags (difficulty and topic) | `/search/`, `/problems/?topic=…&difficulty=…` |

Students submit on an external judge (e.g. train.nzoi.org.nz) with their own accounts.

## Phase 2: backend

| Feature | Needs |
|---|---|
| Admins | Auth + roles (`student`, `admin`) |
| Online judge | Submission API, queue, sandboxed judge workers, private test storage |
| Leaderboard, progress, usage analytics | Submissions table; analytics script |
| Contests | Contests table, time windows, per-contest scoreboard |
| Problem of the week | Table mapping week → problem |

```
Browser ──▶ Site (static, or server-rendered later)
   │
   ├──▶ API + auth + database
   │        ▲ verdicts
   └──▶ Queue ──▶ Judge workers (sandboxed) ──▶ hidden tests (private storage)
```

### Data model (draft)

| Table | Key fields |
|---|---|
| `users` | id, name, role |
| `problems` | id, slug, title, difficulty, topics, time/memory limits |
| `tests` | problem_id, index, input, output, subtask, points |
| `submissions` | id, user_id, problem_id, contest_id?, language, code, verdict, score, time, memory, created_at |
| `contests` | id, title, start, end |
| `contest_problems` | contest_id, problem_id, order |
| `problem_of_the_week` | week_start, problem_id |

## Rules that keep migration easy

1. **Permanent problem IDs.** Every problem gets an ID that never changes or gets reused. Submissions, progress and contests reference it.
2. **One data-access layer.** Pages read content only through `src/lib/`. Moving from Markdown files to a database changes `src/lib/`, not the pages.
3. **Content stays in Markdown in git.** It works for both a static and a server build; a CI step can sync problem metadata into the database later.
4. **Hidden tests never go in this public repo.**
5. **Custom domain before sharing widely.** Moving off GitHub Pages then only means changing DNS.
