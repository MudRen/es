//#pragma save_binary

#include <mudlib.h>

#define SCHOLAR_EMBATTLE_DIR "/d/scholar/embattle/"
#define SCHOLAR_EMBATTLE_SKILL "embattle/"

inherit DAEMON;

int help();

void delete_effect(object man,int ac_effect,int db_effect,int wc_effect)
{
  if (man) {
    if (man->query_temp("embattle_busy")) {
      man->delete_temp("embattle_busy");
      man->set_temp("extra_ac/body",(int)man->query_temp("extra_ac/body")-ac_effect);
      man->set_temp("extra_db/body",(int)man->query_temp("extra_db/body")-db_effect);
      man->calc_armor_class();
      man->set_temp("extra_wc",(int)man->query_temp("extra_wc")-wc_effect);
    }
  }
}

void delete_embattle_effect(object me)
{
  int i,ac,db,wc;
  object *party;

  party=me->query_temp("embattle_party");
  ac=(int)party[0]->query_temp("embattle_ac");
  db=(int)party[0]->query_temp("embattle_db");
  wc=(int)party[0]->query_temp("embattle_wc");
  for(i=0;i<sizeof(party);i++)
    delete_effect(party[i],ac,db,wc);
  return;
}

void check_eight(object me,string other)
{
  int member=0,i;
  object leader,*total_party;

  if (!leader = present(other,environment(me))) {
     tell_object(me,"喂 !! 你在这里要和谁结阵 ?\n");
     return;
  }
  if (me->query_temp("other_party_leader")) {
    tell_object(me,"你现在就可以发动八卦游龙阵了。\n");
    return;
  }
  if (me->query_temp("depend_on_eight")) {
     tell_object(me,"你现在要靠别人来发动阵势。\n");
     return;
  }
  if ((string)leader->query_temp("leader") != (string)leader->query("name")) {
     tell_object(me,"你必须和另一队伍的领导人合作，不是随便乱找。\n");
     return;
  }
  if ((string)leader->query("class")!="scholar") {
     tell_object(me,"要施展八卦游龙阵必须和另一书生所领导的队伍结阵。\n");
     return;
  }
  if ( (string)me->query_temp("leader") != (string)me->query("name")) {
     tell_object(me,"唉 ～ 又不是你领导作战，下什麽命令嘛 ...\n");
     return;
  }
  if( (int)me->query("stop_attack")>0 ) {
     tell_object(me,"( 你上一个动作还没有完成，无法布阵。 )\n");
     return;
  }
  for( i=0;i<sizeof(total_party=(mixed *)me->query_temp("party_members"));i++ )
     if(total_party[i]) {
        if (environment(total_party[i]) == environment(me))
           member++;
     }
  if (member!=4) {
    tell_object(me,"你的队伍不到四个人还想玩八卦游龙阵。\n");
    return;
  }
  leader->set_temp("other_party_leader",me);
  me->set_temp("depend_on_eight",leader);
  tell_object(leader,(string)me->query("c_name")+"和你形成八卦连锁关系。\n");
  tell_object(me,"八卦游龙阵连锁完成。\n");
  return ;
}

void party_disband(object me)
{ 
  object other;

  if (other=me->query_temp("other_party_leader")) {
    other->delete_temp("depend_on_eight");
    me->delete_temp("other_party_leader");
    tell_object(me,"解开八卦游龙阵连锁关系。\n");
    tell_object(other,"解开八卦游龙阵连锁关系。\n");
  }
  else if (other=me->query_temp("depend_on_eight")) {
    other->delete_temp("other_party_leader");
    me->delete_temp("depend_on_eight");
    tell_object(other,"解开八卦游龙阵连锁关系。\n");
    tell_object(me,"解开八卦游龙阵连锁关系。\n");
  }
  else
    write("你要解散啥 ?\n");
  return; 
}

int cmd_embattle(string str)
{
        mapping check1;
	object me,victim,target;
	string name,who,*check2,other,disband;
        int flag;

        if( !str ) return help();

        me=this_player();

	if (sscanf(str,"%s at %s",name,who) != 2) {
          if (sscanf(str,"eight with %s",other) != 1) {
            if (sscanf(str,"eight %s",disband)==1) {
              if (disband=="disband") {
                call_out("party_disband",0,me);
                return 1;
              }
              else 
                return help();
            }
            else
              return help();
          }
          else {
            call_out("check_eight",0,me,other);
            return 1;
          }
        }

	if (!me->query(SCHOLAR_EMBATTLE_SKILL+name)) 
                return notify_fail("咦？你听过这种阵法吗？\n");

	if (!(victim = present(who,environment(me))))
		return notify_fail("喂 !! 你要扁人至少也要找好对象吧 !!\n");

        if ( victim->query("user") ) {
            if( !member_group((string)me->query("name"), "admin") &&
                    (victim->query_level()<5 || me->query_level()<5) )
            return notify_fail("在东方故事中五级以下的玩家不准 PK 和 PK 别人。\n");
        }

        if ((int)victim->query("no_attack"))
            return notify_fail("别轻举妄动，这个东东不能杀就是不能杀 !!\n");

	if ( (string)me->query_temp("leader") != (string)me->query("name"))
		return notify_fail("唉 ～ 又不是你领导作战，下什麽命令嘛 ... 没人理你很糗吧。\n");

	if( (int)me->query("stop_attack")>0 )
		return notify_fail (
			"( 你上一个动作还没有完成，无法布阵。 )\n");

	if( environment(me)->query("no_embattle"))
		return notify_fail( 
			"你正准备列阵时，竟然发现这里是个难以列阵的绝地。\n");

        if( me->query_temp("embattle_busy") ) {
          if( !me->query_attacker() )
            delete_embattle_effect(me);
          else if( member_array(me->query_temp("embattle_victim"),me->query_attackers(),flag)==-1 )
            delete_embattle_effect(me);
          else 
            return notify_fail("你目前正忙著推动阵势，没空想别的事情。\n");
        }

        switch(name) {
        case "eight" :
          call_out("check_party",0,me,victim);
          break;
        default :
          (SCHOLAR_EMBATTLE_DIR+name)->start_embattle(me,victim);
          break;
        };
	return 1;
}

int check_party(object me,object victim)
{
   if (me->query_temp("depend_on_eight"))
     return notify_fail("你现在必须等另一人启动阵势。\n");
   if (!me->query_temp("other_party_leader"))
     return notify_fail("施展八卦游龙阵需要两个对伍一起布阵。\n");
   (SCHOLAR_EMBATTLE_DIR+"eight")->start_embattle(me,victim);
   return 1;
}

int help()
{
		write( @C_HELP
指令格式: embattle <阵势名称> at <攻击目标>

这个指令让你用来推动阵势。一般来说一个由书生为队伍领导人的单一队伍
即可运用阵法攻敌，阵法运作时，可以增加队伍的防御力及破坏力，不过你
也可能被敌人发现破绽或有人临阵脱逃而使得阵法失效。
唯一的例外是当你要施展八卦阵时，需要按照下列步骤：
1. 需要两组四人组成的队伍，当然是书生领队。
2. 一个书生先下 embattle eight with <another leader name>
3. 另一真正启动阵式的书生下 embattle eight at <victim name>
4. 假如没错误,则八卦游龙阵会开始运作。
5. 想要使两个队伍的关系拆散，可用 embattle eight disband
你可以用 embattles 指令回想你还记得的阵势。
C_HELP
		);
    return 1;
}
