#include <mudlib.h>

inherit MONSTER;

void create()
{
        ::create();
        set_level(13);
        set_name( "Spanish Spider", "��������֩��" );
        add ("id", ({ "spider" }) );
        set_short( "��������֩��");
        set_long(@LONG
������ԭװ���ڴ�֩�룬�����⸽����֩������Ŷ�������Ĺ�
LONG
        );
        set_perm_stat("dex",23);
        set_skill( "dodge", 50 );
        set( "alignment", -500 );
        set( "race", "insect" );
        set( "gender", "male" );
        set( "hit_points", 300 );
        set( "max_hp", 300 );
        set( "aim_difficulty",
        ([ "critical":40,"weakest":40,"ganglion":10,"vascular":90 ]) );
        set_natural_weapon( 20, 15, 30 );
        set_natural_armor( 20, 40 );
        set ("special_defense", ([
                "monk": 20, "scholar": 20, "all": 20 , "none" : 20]) );
        set_c_limbs( ({ "ͷ��", "����", "ǰ��"}) );
        set_c_verbs( ( {"%s�嵽����ǰ��������³�һ����Һ��%sһ������",
                        "%sͻȻ�����������������ٴӿ���������ҧ%s",
                        "%s�Ĵ��Ҵܣ��ó��������Ľ�����%s"}));
}
