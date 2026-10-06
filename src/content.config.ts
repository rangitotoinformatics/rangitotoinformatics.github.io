import { defineCollection } from 'astro:content';
import { glob } from 'astro/loaders';
import { z } from 'astro/zod';

const folderName = ({ entry }: { entry: string }) => entry.split('/')[0];

const problems = defineCollection({
  loader: glob({ pattern: '*/index.md', base: './src/content/problems', generateId: folderName }),
  schema: z.object({
    problemId: z.number().int(),
    title: z.string(),
    difficulty: z.enum(['Easy', 'Medium', 'Hard']),
    topics: z.array(z.string()),
  }),
});

const editorials = defineCollection({
  loader: glob({ pattern: '*/editorial.md', base: './src/content/problems', generateId: folderName }),
});

const lessons = defineCollection({
  loader: glob({ pattern: '*.md', base: './src/content/lessons' }),
  schema: z.object({
    title: z.string(),
    order: z.number().int(),
    description: z.string().optional(),
  }),
});

export const collections = { problems, editorials, lessons };
