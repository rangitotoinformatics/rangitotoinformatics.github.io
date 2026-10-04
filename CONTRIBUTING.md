# Contributing

Open a pull request. The build checks every file's frontmatter, so a typo in a field fails CI instead of breaking the site.

## Add a lesson

Create `src/content/lessons/<slug>.md`:

~~~md
---
title: Two pointers
order: 4                 # position in the lesson list
topics: [two pointers]
---

Lesson content in Markdown. Math: $O(n \log n)$. Code blocks: ```cpp ... ```.
~~~

## Add a problem

Create a folder `src/content/problems/<slug>/`:

| File | Required | Content |
|---|---|---|
| `index.md` | yes | Frontmatter + statement |
| `editorial.md` | no | Editorial (no frontmatter needed) |
| `solution.cpp` | no | Model solution (`.py`, `.java` also work) |

`index.md` frontmatter:

```yaml
---
id: P0004                # next unused ID; never change or reuse an ID
title: Two Sum
difficulty: medium       # easy | medium | hard
topics: [two pointers, sorting]
lessons: [two-pointers]  # lesson slugs; the lesson page lists this problem automatically
source: { name: Rangitoto Informatics }
submitUrl: https://...   # where students submit (e.g. train.nzoi.org.nz)
timeLimit: 1             # seconds (optional)
memoryLimit: 256         # MB (optional)
---
```

### Problems from other sites

Do not copy statements from NZOI, CSES or other judges. Leave the body of `index.md` empty, set `source` and `submitUrl` to the original, and add your own editorial and solution.

### Test data

Never commit hidden test data to this public repository. It will live in the judge's private storage (see `docs/architecture.md`).
