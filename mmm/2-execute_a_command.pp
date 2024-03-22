# exec resource to kill the process "killmenow"

exec { 'Killmenow':
  command  => 'pkill killmenow',
  provider => 'shell'
}
