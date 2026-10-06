import { getCollection } from 'astro:content';

export async function getLessons() {
  const all = await getCollection('lessons');
  return all.sort((a, b) => a.data.order - b.data.order);
}