import { defineConfig } from 'astro/config';
import { unified } from '@astrojs/markdown-remark';
import remarkMath from 'remark-math';
import { remarkAlert } from 'remark-github-blockquote-alert';
import rehypeKatex from 'rehype-katex';


export default defineConfig({
  site: 'https://rangitotoinformatics.github.io',
  markdown: {
    processor: unified({
      remarkPlugins: [remarkMath, remarkAlert],
      rehypePlugins: [rehypeKatex],
    }),
  },
});
