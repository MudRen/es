#include "mudlib.h"
inherit MONSTER;

void create()
{
	::create() ;
	seteuid(getuid()) ;
	set_level(8);
	set_name("fisher", "���");
	add ("id", ({ "fisher", "fish" }) );
	set_short( "���");
	set_long(
		"����һλʯ�ٴ����������������ʲ���������Ͷ���..\n"
		);
	set_perm_stat("str", 14);
	set_skill( "dodge", 60 );
	set( "max_hp", 180 );
	set( "hit_points", 180 );
	set( "gender", "male" );
	set( "race", "human" );
	set( "alignment", 50 );
	set_natural_armor( 30, 5 );
	set_natural_weapon( 25, 10, 20 );
        set( "inquiry", ([
              "fish" : "@@ask_fish",
              "da" : "@@ask_da"
              ]));
}
string c_call(object who)
{
	if ((string)who->query("gender") == "female")
	return (!who->query("spouse")) ? "С��" : "����" ;
	else
	return (!who->query("spouse")) ? "С��" : "���" ;
}
void ask_fish()
{
        if (!(int)this_player()->query_temp("feed_fish")==1) {
write (
"��λ���˵��: " + c_call(this_player()) +"���Բ�����Ҫ���ҵ���...\n");
return ;
}
write (
"��λ���˵��: " + c_call(this_player()) +"����������Щ�㣬ȫ���Ǵ�ƽ̨�ϵ���\n"
"���ģ���Ҫ����˼��Ҳ����ȥ���Կ������ˣ�������㣬�ǳ�\n"
"ϲ����ζ�����ص�������Ϻ��������ѵ��ĵ���\n");
return ;
}
void ask_da()
{
        if ((int)this_player()->query_temp("da_quest/ask")<1) {
        write (
        "��λ���˵��: " + c_call(this_player()) +"���Բ��𣬴�����ס����..\n");
        return ;
        }
        write (
        "��λ���˵��: " + c_call(this_player()) +"����Ҳ֪�������������˰�.......\n"
        "����Ҳ��������������ҽ����ȫ����������˵: ������û����ֻ����һ\n"
        "ֱ��Ϊ����֢���Բ��·������Ӫ��������������ҵ�����ϲ���Ե�\n"
        "������һ�����ܿ���ָܻ������������ǣ�˭֪������ϲ����ʲ��?\n");
        return ;
 }       
