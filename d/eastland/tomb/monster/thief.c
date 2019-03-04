#include "../almuhara.h"

inherit MONSTER;

void create ()
{

	::create();
    set_level(5);
    set_name("Tomb Thief","��Ĺ��");
    add ("id", ({ "thief"}) );
    set_short( "��Ĺ��");
    set_long(
@C_LONG
һ����Ĺ������������Ѱ��Ĺ����ڡ�
C_LONG
	);
    set("alignment",-300);
    set( "gender", "male" );
    set( "race", "human");
    set( "unit", "��" );
    set_perm_stat( "str", 10);
    set_perm_stat( "dex", 10);
	set_skill("dagger",40);
    set ("max_hp",150);
    set ("max_sp",0);
    set ("hit_points",150);
    set ("spell_points",0);
    set ("wealth", ([ "gold":10]) );
    set_natural_weapon(20,5,13);
    set_natural_armor(40,5);
    set ("weight", 350);
    set("chat_chance",15);
    set("chat_output", ({
        "��Ĺ��˵��: ��˵�ص׹㳡�����л��ؿ����ҵ���Ĺ֮��.....\n",
        "��Ĺ��˵��: ��˵�ص׹㳡�����л��ؿ����ҵ���Ĺ֮��.....\n",
        "��Ĺ����������: ��һ��Ҫ�ҵ��ǿű��顣\n",
    	"��Ĺ��аЦ������˵��: ������¸���������ͬ�����ޱ����� ??\n",
    	"��Ĺ��ץץ����ͷ���ƺ���˼��ʲ�ᡣ\n" }) );
    set("att_chat_output",({   
        "��������: �㲻����ˣ����Ҹ��������� ?\n"
       }) );
    set( "moving", 1 );
    set( "speed", 40 );
    set( "patrol", ({ "east", "east", "north", "north", "north", "east",
		"north", "north", "east", "east" }) );
    wield_weapon(WEAPONS"/dagger1");
}


