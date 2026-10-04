import { defineCollection, z } from 'astro:content';
import { glob } from 'astro/loaders';

const folderId = ({ entry }: { entry: string }) => entry.split('/')[0];

const lessons = defineCollection({
  loader: glob({ pattern: '*.md', base: './src/content/lessons' }),
  schema: z.object({
    title: z.string(),
    order: z.number(),
    topics: z.array(z.string()).default([]),
  }),
});

const problems = defineCollection({
  loader: glob({ pattern: '*/index.md', base: './src/content/problems', generateId: folderId }),
  schema: z.object({
    // Permanent ID. Future judge, submissions and progress reference this, so never change or reuse it.
    id: z.string().regex(/^P\d{4}$/),
    title: z.string(),
    difficulty: z.enum(['easy', 'medium', 'hard']),
    topics: z.array(z.string()).default([]),
    lessons: z.array(z.string()).default([]),
    source: z.object({ name: z.string(), url: z.string().url().optional() }).optional(),
    submitUrl: z.string().url().optional(),
    timeLimit: z.number().optional(),
    memoryLimit: z.number().optional(),
  }),
});

const editorials = defineCollection({
  loader: glob({ pattern: '*/editorial.md', base: './src/content/problems', generateId: folderId }),
  schema: z.object({}),
});

export const collections = { lessons, problems, editorials };
