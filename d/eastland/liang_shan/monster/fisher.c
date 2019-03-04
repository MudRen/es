#include "mudlib.h"
inherit MONSTER;

void create()
{
	::create() ;
	seteuid(getuid()) ;
	set_level(8);
	set_name("fisher", "����");
	add ("id", ({ "fisher", "fish" }) );
	set_short( "����");
	set_long(
		"����һλר�����˵���ĵ��ͣ������ƺ��ɼ���������...\n"
		);
	set_perm_stat("str", 12);
	set_skill( "dodge", 40 );
	set( "max_hp", 150 );
	set( "hit_points", 150 );
	set( "gender", "male" );
	set( "race", "human" );
	set( "alignment", 50 );
	set_natural_armor( 25, 5 );
	set_natural_weapon( 20, 6, 15 );
        set( "chat_chance",16);  
        set("chat_output",({"���Ͱѵ�������һ��������ʲ�ᶼû��...\n",
                            "���Ͱѵ��������ͷ�ذ����...\n",
                            "����˵��: �����浹ù....\n",
                            "���Ͳ�ͣ����Ū���Ľ�ֺ....\n"}));
        equip_armor("/d/eastland/liang_shan/obj/rod");
        equip_armor("/d/eastland/liang_shan/armor/hat");
        set( "inquiry", ([
              "fish" : "@@ask_fish"
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
write (
"��λ����˵��: " + c_call(this_player()) +"������кܶ�����...\n");
return ;
}

