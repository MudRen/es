//#pragma save_binary

//	File	:  /cmds/std/_history.c
//	Creator	:  Probably Wayfarer
//
//	This command displays the list of the user's past commands
//	stored in the history stack.

#include <mudlib.h>
inherit DAEMON;

#define log( x ) log_file( "hist_err",wrap( x ) )

int help();

int cmd_history(string str) {
   int i,tptr;
   int max,cmd_num,ptr;
   string *history_queue;
   object act_ob;

   act_ob = previous_object();

   if ((int)act_ob->query_npc()) return 0 ; 
   max = (int)act_ob->query_max();
   cmd_num = (int)act_ob->query_cmd_num();
   ptr = (int)act_ob->query_ptr();
   history_queue = (string *)act_ob->query_history();

   if(!history_queue || !pointerp(history_queue)) {
   write("History seems to be broken. Please inform an Admin.\n");
   return 1; }

   tptr = ptr;

   for(i = max - 1; i >= 0; i--)
   {
      if(history_queue[tptr])
         printf("%4d %s\n",cmd_num - i,history_queue[tptr]);
      tptr++;
      if(tptr == max)
         tptr = 0;
   }
   return 1;
}

int help() { 
write(@HELP

这条指令列出你曾经使用过的指令，并可以重复调用它们.

  !<指令数>	: 重复运行指令<数>.
  !!		: 重复执行你刚运行过的指令.
  !!<物品>	: 在重复的指令后添加<物品>
  ^^<指令>	: 在重复指令后添加<指令>
  
例:
   7 grovel
   8 kill orc
   9 knock on east door
  10 bounce
  11 look

  !7	- 重复执行第7号指令\"grovel\"
  !-2	- 重复执行倒数第2号指令\"bounce\"
  !k	- 重复简写为k的指令\"knock on east door\"

HELP
);
    return 1;
}
