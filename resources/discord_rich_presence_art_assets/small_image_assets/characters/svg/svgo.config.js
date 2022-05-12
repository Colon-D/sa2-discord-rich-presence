module.exports = {
    js2svg: {
        indent: 2,
        pretty: true,
    },
    plugins: [
        'removeComments',
        'convertStyleToAttrs',
        'cleanupNumericValues',
        'convertColors',
        'collapseGroups',
        'convertTransform',
        'sortAttrs',
        'inlineStyles',
        'removeStyleElement'
    ],
};
