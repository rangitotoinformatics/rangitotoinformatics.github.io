// The only module pages use to read content. When a backend is added,
// swap these implementations (e.g. to fetch from a database) without touching pages.
import { getCollection, getEntry } from 'astro:content';

export const DIFFICULTIES = ['easy', 'medium', 'hard'] as const;

const solutionFiles = import.meta.glob('/src/content/problems/*/solution.*', {
  query: '?raw',
  import: 'default',
  eager: true,
}) as Record<string, string>;

const LANGS: Record<string, string> = { cpp: 'cpp', py: 'python', java: 'java' };

export async function getLessons() {
  const lessons = await getCollection('lessons');
  return lessons.sort((a, b) => a.data.order - b.data.order);
}

export const getLesson = (slug: string) => getEntry('lessons', slug);

export async function getProblems() {
  const problems = await getCollection('problems');
  return problems.sort((a, b) => a.data.id.localeCompare(b.data.id));
}

export const getProblem = (slug: string) => getEntry('problems', slug);

export const getEditorial = (slug: string) => getEntry('editorials', slug);

export function getSolution(slug: string) {
  const path = Object.keys(solutionFiles).find((p) => p.split('/').at(-2) === slug);
  if (!path) return undefined;
  const ext = path.split('.').at(-1) ?? '';
  return { code: solutionFiles[path], lang: LANGS[ext] ?? ext };
}

export async function getProblemsForLesson(lessonSlug: string) {
  return (await getProblems()).filter((p) => p.data.lessons.includes(lessonSlug));
}

export async function getTopics() {
  const problems = await getProblems();
  return [...new Set(problems.flatMap((p) => p.data.topics))].sort();
}
