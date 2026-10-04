# Rangitoto Informatics

The informatics club website: lessons, problems with editorials and model solutions, and search.

Live at <https://rangitotoinformatics.github.io>.

## Develop

Requires Node 20+.

```sh
npm install
npm run dev      # http://localhost:4321 (search only works after a build)
npm run build    # type-check, build to dist/, and index search
npm run preview  # serve dist/
```

Pushing to `main` deploys to GitHub Pages through `.github/workflows/deploy.yml`.

## Structure

```
src/content/lessons/<slug>.md                 lessons
src/content/problems/<slug>/index.md          problem metadata + statement
src/content/problems/<slug>/editorial.md      editorial (optional)
src/content/problems/<slug>/solution.cpp      model solution (optional)
src/content.config.ts                         content schemas
src/lib/content.ts                            the only content-access layer pages use
src/pages/                                    routes
docs/architecture.md                          current design and future backend plan
```

See [CONTRIBUTING.md](CONTRIBUTING.md) for how to add lessons and problems.

## Licence

Code: MIT. Lessons, statements and editorials: CC BY 4.0, unless a problem's `source` says otherwise.
