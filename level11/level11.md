# LEVEL11


i our home directory we see a file with lua extention with flag11 extention 
we see that there is something runinng on the port 5151 
when there is a connection from the client we see that we need to enter a password 
since there is no check in the password any command should be executed as flag11 let's try to enter 
 password, as expected.


```
level11@SnowCrash:~$ ls -l
total 4
-rwsr-sr-x 1 flag11 level11 668 Mar  5  2016 level11.lua

level11@SnowCrash:~$ cat level11.lua
#!/usr/bin/env lua
local socket = require("socket")
local server = assert(socket.bind("127.0.0.1", 5151))

function hash(pass)
  prog = io.popen("echo "..pass.." | sha1sum", "r")
  data = prog:read("*all")
  prog:close()

  data = string.sub(data, 1, 40)

  return data
end


while 1 do
  local client = server:accept()
  client:send("Password: ")
  client:settimeout(60)
  local l, err = client:receive()
  if not err then
      print("trying " .. l)
      local h = hash(l)

      if h ~= "f05d1d066fb246efe0c6f7d095f909a7a0cf34a0" then
          client:send("Erf nope..\n");
      else
          client:send("Gz you dumb*\n")
      end

  end

  client:close()
end
```

# we can solve the challenge by 
```
level11@SnowCrash:~$ nc 127.0.0.1 5151
Password: `getflag` > /tmp/token
Erf nope..
level11@SnowCrash:~$ cat /tmp/token
Check flag.Here is your token : fa6v5ateaw21peobuub8ipe6s

```
