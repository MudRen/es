//#pragma save_binary
 
//	File	:  /cmds/xtra/_zap.c
//	Creator	:  Watcher@TMI  (03/27/93)
//
//	This is the wizard zap command which kills the intended target.

#include <mudlib.h>
#include <logs.h>
#include <uid.h>

inherit DAEMON;
 
#define SYNTAX	"Syntax: zap [target]\n"
 
int cmd_zap(string str) {
   object target, targetenv;
 
   notify_fail( SYNTAX );
   if(!str || str == "")  return 0;
 
   str = lower_case(str);

   targetenv = environment(this_player());
   if (!targetenv) {
       write("A flash a lightning is consumed in the dark void.\n");
       return 1;
   } 
   target = present(str, targetenv);
 
   if(!target) {
   	   write("Zap: There is no such living object here.\n");
       return 1;
   }
 
   if(!living(target)) {
       write("Zap: That object is not alive.\n");
       return 1;
   }
 
   if(target->link_data("dead") || target->query_dead() || 
      target->query("dead")) {
       write("Zap: That object is already dead.\n");
       return 1;
   }
 
   if(wizardp(target) && target->query("immortal")) {
       write("Zap: That wizard is immortal, and cannot be killed.\n");
       return 1;
   }
 
   tell_room(environment(this_player()),
	(string)this_player()->query("c_name") + "����һ�����磬ֱֱ������" +
	(string)target->query("c_name") + 
	"����.\n", ({ this_player(), target }));
 
   if(target != this_player())
   tell_object(target,
	(string)this_player()->query("c_name") + "ͻȻ����һ�����磬" +
	"ֱֱ�����������ϣ���ͻȻ��ǰһ�� ...\n");

   if(target != this_player())
   write("���ٻ����ף��ֽ�" + (string)target->query("c_name") + ".\n");
   else write("���ٻ����������Լ�.\n");
 
   target->receive_damage( 2000 );	// Overkill  <grin>

#ifdef ZAP_LOG
  seteuid(ROOT_UID);
  if( !member_group(this_player()->query("name"), "admin") )
   	log_file(ZAP_LOG, "************  ["+extract(ctime(time()), 4, 15)+"]\n"+
   	  "Where: "+file_name(environment(this_player()))+", Wizard: "+
   	  (string)this_player()->query("name")+", Zapped: "+
   	  (string)target->query("name")+",\n"+identify(target)+"\n"
   	  
	);
#endif

    return 1;
}
 
int help() {

   write( SYNTAX + "\n" +
    "This command allows a wizard to strike dead any living mortal object.\n" +
    "If a wizard has their \"immortal\" property set, they cannot be " +
    "killed.\nBe warned ... Admins do not take the zapping of players " +
    "lightly.\n");

return 1; }

