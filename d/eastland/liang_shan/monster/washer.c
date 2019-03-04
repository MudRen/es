#include "mudlib.h"
inherit MONSTER;

void create()
{
	::create() ;
	seteuid(getuid()) ;
	set_level(6);
	set_name("Da", "����");
	add ("id", ({ "da", "Da" }) );
	set_short( "����");
	set_long(
		"���������꣬Ϊ�˲�֪����ԭ�����˴򹤣�\n"
		);
	set_perm_stat("str", 10);
	set_skill( "dodge", 30 );
	set( "max_hp", 120 );
	set( "hit_points", 120 );
	set( "gender", "male" );
	set( "race", "beholder" );
	set( "alignment", 20 );
	set_natural_armor( 10, 2 );
	set_natural_weapon( 10, 4, 10 );
        set( "chat_chance",5);  
        set("chat_output",({"����������: ���̵Ĳ���û�ã������??\n",
                            "���갢����ƴ�����Ĺ���....\n"}));
        set( "inquiry", ([
              "sick" : "@@ask_sick",
              "grandmother" : "@@ask_grama",
              "fish" : "@@ask_fish"
              ]));
}
string c_call(object who)
{
	if ((string)who->query("gender") == "female")
	return (!who->query("spouse")) ? "���" : "����" ;
	else
	return (!who->query("spouse")) ? "���" : "����" ;
}
void ask_grama()
{
write (
"���갢��̾��һ������˵��: ����ʶ�ҵ�������? ����Ӧ��֪����\n"
"�����������?\n");
this_player()->set_temp("da_quest/ask",1);
return ;
}

void ask_sick()
{
if ((int)this_player()->query_temp("da_quest/ask")<1) {
write (
"���갢��˵��: ร���λ" + c_call(this_player()) +"��������? Ҳ��\�����������կ\n"
"�еĵ�һ��ҽ������ȫ����......\n");
return ;
}
write (
"���갢��˵��: ��λ���ĵ�" + c_call(this_player()) +"���ҼҾ��ڴ������ʯ�ٴ壬�����˶�����\n"
"ֻ�����̺�������Ϊ��������������ǰ����ͻȻ����һ����ֵĲ�����Ҳ����\n"
"կ�еĵ�һ��ҽ������ȫ����ȥ����������Ȼ����Ч��������������Ŭ����\n"
"׬Ǯ�����ܲ��ܰ����̴�ȥĬ��˹��ҽ��....\n");
return ;
}
void ask_fish()
{
if ((int)this_player()->query_temp("da_quest/ask")<1) {
write (
"���갢��˵��: ร���λ" + c_call(this_player()) +"���Բ��������ڹ���\n"
);
return ;
}
write (
"���갢��˵��: ��λ���ĵ�" + c_call(this_player()) +"������Ҫ��������ϲ�������?\n"
"�����̳�˵����ǰ�������һ�ֻƽ�ɫ�����㣬������ϲ����ʳ��������⼸����\n"
"�Ѿ����ټ�����....\n");
return ;
}
