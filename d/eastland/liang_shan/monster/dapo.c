#include "mudlib.h"
#include <stats.h>
#include <conditions.h>

inherit MONSTER;

void create()
{
	::create() ;
	seteuid(getuid()) ;
	set_level(15);
	set_name("Grandmother Da", "������");
	add ("id", ({ "da", "grandmother" }) );
	set_short("������");
	set_long(
		"�㿴��һ�����ϵ������ţ����ڴ���������է��֮�º�����\n"
		"��������һϢ�����ӣ�����ϸ������ȴ����û�в��ĺ��ء�\n");
	set_perm_stat("dex", 10);
	set_perm_stat("kar", 17);
	set_perm_stat("str", 13);
        set( "chat_chance",20);  
        set("chat_output",({"�����Ų�ͣ�ķ�������.......��.....��.....\n"}));
	set_skill( "dodge", 30 );
	set( "max_hp", 380 );
	set( "hit_points", 380 );
	set( "gender", "female" );
	set( "race", "beholder" );
	set( "alignment", 100 );
	set( "tactic_func", "become_weak" );
	set_natural_armor( 35, 20 );
	set_natural_weapon( 34, 15, 20 );
	set( "forgetful", 1 );
	set( "time_to_heal", 5 );
        set( "inquiry", ([
              "sick" : "@@ask_sick",
              "food" : "@@ask_food"
              ]));
}
string c_call(object who)
{
	if ((string)who->query("gender") == "female")
	return (!who->query("spouse")) ? "����" : "̫̫" ;
	else
	return (!who->query("spouse")) ? "�ܵ�" : "����" ;
}
void ask_sick()
{
write (
"������̾��һ������˵��: ����������...\n");
return ;
}

void ask_food()
{
write (
"������˵��: ร���λ" + c_call(this_player()) +"��������ϲ����ʲ����??\n"
"ס����嵱Ȼϲ����������ֻ���Ҳ��Ŀ��ƨ�ˣ������������??\n");
return ;
}

int become_weak()
{
	object victim;

	if( random(20)>4 || !(victim= query_attacker()) ) return 0;
    tell_room( environment(this_object()),
            "\n�����Žе�: ���������˶�Ҫ�۸�....�㲻�±���Ⱦ��??\n"
            "����������ŵĻ�������������Щ���Ծ�.......\n\n",
		this_object() );
	(CONDITION_PREFIX + "weak")->apply_effect( victim, 2, 12 );
	return 1;
}

int accept_item(object me,object item)
{
	string name;
	name=(string)item->query("name");
     if ( !name || (name!="fish meat") ) return 1;
{
     tell_object(me,
@MEAT
�����Žӹ��ƽ��λ�������⣬������������....

û�뵽���ﻹ�лƽ��λ����㣬��ʮ��û�г�������������ζ��...

MEAT
	);
//      command("eat meat");
        item->remove();
     tell_object(me,
@HAHA
������̧ͷ�����㣬˵��: Ϊ���ٳԵ��ƽ��λ����㣬�������ܹ�������
��������? ˵��: ���ݽǵ��������ó����ͣ�׼��Ҫȥ����....

��������˵��������������ʰ��������е��ޱȵĿ��֡�
HAHA
	);
	  if( (int)this_player()->query_quest_level("A_da")<1 ) {
		write("������˴��������񣬵õ���7000�㾭��ֵ\n");
		this_player()->finish_quest( "A_da", 1 );
		this_player()->gain_experience(7000);
	   }
		                           return 1;
}
}
