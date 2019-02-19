workflow "New workflow" {
  on = "push"
  resolves = ["Lint"]
}

action "Lint" {
  uses = "cclauss/GitHub-Action-for-cpplint@master"
  args = "cpplint --filter=-build/include_subdir,-whitespace/forcolon,-whitespace/indent --recursive src"
}
