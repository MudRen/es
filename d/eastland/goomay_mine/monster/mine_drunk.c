#include <../zeus.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(16);
	set_name( "drunk", "�Ͼƹ� ����" );
	set_short( "�Ͼƹ� ����" );
	set_long(@AA
�Ͼƹ���һ���ǳ����ص��ˣ�û����֪�������״Ӻδ�����������Ʋ���ڣ����
�ľ���ǳ����������ƼǺţ���������ǰ������������˫���Ͽ���˫��������Ʋ�
�������������µ��׼ҵ��ӣ����������ܵ��ƾ�͵�Ⱦ��ˣ�
AA
	);
    set( "alignment",-500);
    set( "gender", "male" );
    set( "race", "dwarf" );
    set( "unit", "��" );
	set_perm_stat( "dex", 20 );
	set_perm_stat( "str", 22 );
	set_perm_stat( "kar", 16 );
	set_skill("unarmed",90);
	set_skill("dodge",70);
	set("special_defense", ([ "all":20, "none":10 ]) );
	set("aim_difficulty", ([ "critical":20, "vascular":12, ]) );
	set("max_hp", 400);
	set("max_fp", 600);
	set("hit_points", 400);
	set("force_effect", 2);
	set("force_points", 600);
        set("attack_skill","monk/fist/drunk_fist");
        set("gonfus/drunk-fist",100);    
	set("wealth/gold", 50);
	set_natural_weapon(45,20,40);
	set_natural_armor( 66, 19 );
        set("weight", 700);
        set("inquiry",([
             "ghost":"@@ask_ghost"
             ]));
    equip_armor( ZOBJ"/boots" );
    equip_armor( ZOBJ"/red_coat" );
}
int ask_ghost()
{    tell_object(this_player(),
@ASK
�ҵ�û�м�������ֻ֪�����ϴ�ĵܵܳ������Ǳ߳��룡
ASK
);
     this_player()->set_temp("ask_ghost",1);
     }