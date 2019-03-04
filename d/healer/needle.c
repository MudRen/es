////#pragma save_binary

#include <mudlib.h>
#include "/d/healer/healer.h"

inherit GUILD_OB;
inherit OBJECT;

void create()
{
	seteuid( getuid() );
	guild_ob::create();
	set( "extra_look", "@@query_extra_look");
	set_class_name("healer");
	set("short","����");	
#include <compress_obj.h>
	set_name("needle", "����");
	set_long( @LONG
����һ��ϸС�����룬��ҽ��������������β�����Ȼ��������
�ܴ��������ǵ���һ������ḻ����ҽ�����У��ͻ���һ����
�˻�ɱ�˵������������Ҫ֪���й���������ҽ�ߵ���ϸ��;��
������ help needle ָ�
LONG
	);

	set( "unit", "��" );
	set( "weight", 1 );
	set( "skills_effect", "lawful_only" );
	set( "bandage_reward_func", "bandage_reward" );

}

int help_bbpower();

string query_extra_look()
{
  string msg;
  int op_succ_count; 
  int op_fail_count;
  
  if (!op_succ_count=environment()->query("op_succ_count")) op_succ_count=0;
  if (!op_fail_count=environment()->query("op_fail_count")) op_fail_count=0;
  msg ="$N���ϴ�����ҽ��������������β������롣\n";
  if ( op_succ_count==0 && op_fail_count==0 ) msg += "$N���������˶���������\n";
  else if ( op_fail_count == 0 ) 
       msg += "$N��һ���������˶���"+chinese_number(op_succ_count)+"������, ������ȫ�ɹ��ˡ�\n";
  else if ( op_succ_count == 0 )
       msg += "$N��Ȼ�Ǹ���ӹҽ....��"+chinese_number(op_fail_count)+"���˶�������, ���ȫ�������ˡ�\n"; 
  else msg += "$N�����˶���"+chinese_number(op_succ_count+op_fail_count)+"������, ������"+ 
              chinese_number(op_succ_count)+"���ǳɹ��ġ�\n";
  return msg;
}  

void init()
{
	// Apply guild_ob checks
	guild_ob::init();

	add_action("help", "help");
	add_action("info", "info");
	add_action("do_healers", "healers");
	add_action("do_chat", "healer");
    	add_action("do_list_meridian","meridian") ;
	add_action("do_bandage_power", "bbpower");
}

int do_healers()
{
	return guild_ob::list_guild_members();
}

// The guild channel
int do_chat(string arg)
{
	if( !arg )
		return notify_fail( "�����������ҽ��˵ʲ�᣿\n");
	return guild_ob::guild_line(arg);
}

int do_bandage_power(string level)
{
    object p;
    int effect, ali, orig;

    p = this_player();
    if (p->query_temp("acup_effect/potential") == 1)
	return notify_fail("Ǳ�ܼ�����״̬�£��޷���ȷ��������������\n");

    switch (level)
    {
	case "max": p->set("bandage_power", 1);
		    break;
        case "regular": p->set("bandage_power", 0.8);
                    break;
        case "normal": p->set("bandage_power", 0.6);
                    break;
        case "minor": p->set("bandage_power", 0.4);
                    break;
        case "mini": p->set("bandage_power", 0.2);
                    break;
	default:
		help_bbpower();
		return 1;
    }
    write("Ok.\n");
    orig = p->query_skill("bandage");
    effect = p->query_perm_skill("bandage");
    ali = p->query("alignment");
    if (ali < -400) effect += effect * ((ali<(-10000)?-10000:ali)+400) / 32000;
    effect = to_int(effect * (float)p->query("bandage_power")) - orig;
    p->modify_skill("bandage", effect);
    return 1;
}

int lawful_only(object me, string skill_name, int effect)
{
	// Changed by Lilia@ES Apr. 12, 1996

	int ali;
	
	ali = (int)me->query("alignment");
	if( ali < -400 )
	{
	    switch(skill_name)
	    {
		case "bandage":
		case "operation":
		case "first-aid":
		case "clotting":
		    effect += effect * ((ali<(-10000)?-10000:ali)+400) / 32000;
		    break;
		default: break;
	    }
	}
	if (me->query("bandage_power") && skill_name == "bandage")
	    effect = to_int(effect * (float)me->query("bandage_power"));
	return effect;
}

// the reward function when a healer bandage others.
void bandage_reward(object me, object dest)
{
	int skill, hp, max_hp, exp, dest_ali;
	
	max_hp = (int)dest->query("max_hp");
	hp = (int)dest->query("hit_points");
	skill = (int)me->query_skill("bandage", 1);
	dest_ali = (int)dest->query("alignment");

	if( dest_ali > 0 ) {
		me->add("alignment", 1);
		me->gain_experience( skill*(max_hp-hp)/max_hp );
	} else {
		me->add("alignment", dest_ali/100);
		me->gain_experience(1);
	}
	return;
}

int info(string arg)
{
	switch(arg) {
		case "history"  : cat( GUILD_DATA"c_healer_history" ); break;
		case "commands" : cat( GUILD_DATA"c_healer_commands" ); break;
		case "skills"   : cat( GUILD_DATA"c_healer_skills" ); break;
		case "topics"   :
		default: 
				cat( GUILD_DATA"c_topics");
			break;
	}
	return 1;
}

int help(string arg)
{
      if (arg == "bbpower") { help_bbpower(); return 1; }
      if( !arg || arg!="needle" ) return 0;
      cat( GUILD_DATA"c_needle");
      return 1;
}

int do_list_meridian()
{
      int i ,lenth; 
      string *temp ;
      mapping learned ;
  
      learned = this_player()->query("prac_meridians") ;
      if(!learned) 
          return notify_fail("�����ڶ�ÿ��Ѩ��������Ϥ��\n") ;

      temp = keys(learned) ;      
      lenth = sizeof(temp) ;

      write(sprintf("�����������յľ��繲��%d�����ֱ�Ϊ��\n",lenth) ) ;
      for( i=0 ; i<lenth ; i++)
         {
           write(temp[i]+"��\n") ; 
         }
      return 1 ;           
}

int help_bbpower()
{
    cat(GUILD_DATA"c_bbpower");
    return 1;
}
