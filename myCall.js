Function.prototype.myCall = function (context, ...args) {
    context = context || globalThis;
    let key = Symbol();
    // context[key] = this;
    Object.defineProperty(context, key, {
        value: this,
        enumerable: false,
    });
    const result = context[key](...args);
    delete context[key];
    return result;
}