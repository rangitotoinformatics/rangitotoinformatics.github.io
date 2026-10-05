import { getCollection, getEntry } from 'astro:content';

export async function getProblems() {
  const all = await getCollection('problems');
  return all.sort((a, b) => a.data.problemId - b.data.problemId);
}

export async function getEditorial(slug: string) {
  return getEntry('editorials', slug);
}
