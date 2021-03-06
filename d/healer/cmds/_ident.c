//#pragma save_binary

#include <mudlib.h>
inherit DAEMON;

int cmd_ident(string arg)
{
  object target;
  string c_realname;
  string realname;
  string s;
  string temp;
  int skills;
  int skill_require;
  int intelligent;
  
  if (! ( arg || arg=="") ) 
    return notify_fail("你要辨识什麽东西??\n");
  if (! target = present(arg,environment(this_player() ) ) )
    return notify_fail("你要辨识的东西不在这里。\n");
  c_realname = target->query("c_realname");
  realname   = target->query("realname");
  skills     = this_player()->query_skill("herbs");
  skill_require = target->query("skill_require");
  intelligent = this_player()->query_stat("int");
  
  tell_room(environment(this_player()),this_player()->query("c_name")+
            "戴上他的老花眼镜,对著"+target->query("c_name")+
            "仔细的观查半天。\n",this_player() );
  if ( (! c_realname) || (! realname) || 
     ( skills < skill_require ) || (intelligent <10) )
    return notify_fail("你对著"+target->query("c_name")+"辨识半天,还是看不出个所以然来。\n");
  
  tell_object(this_player(),
              "根据你的经验, 你判断这是一棵"+c_realname+"("+realname+")。\n");
  sscanf(identify(target),"%s/%s",s,temp);
  if (this_player()->query_temp("last_verify")==0)
    this_player()->set_temp("last_verify",temp+"\n" );
  else
    this_player()->add_temp("last_verify",temp+"\n" );
  return 1;
}

int help()
{
  write(
  @C_HELP
指令格式: ident <植物名>

这个指令让你能够正确辨识出一种植物。
由於药用植物很多都长的极为相似, 如果不加辨识就加以采集,
很可能会发生药物误用的事情, 甚至造成无法弥补的错误, 因此
刑老爹规定所有healer在采药前一定要先加以辨识。

如果你无法成功的辨识一种不知名的植物, 可能是因为你的智慧
太低, 也可能是因为对药草辨识<herbs> 的技能认识不够, 可以
先到公会充实自己後再试一次。
C_HELP
  );
  return 1;
}
