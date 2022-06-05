var log = console.log
console.log('hello world')

window.$ = function(target){
  return document.querySelector(target)
}

var root = $("#root")
root.innerHTML = "root"

