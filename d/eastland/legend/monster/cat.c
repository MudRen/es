#include <mudlib.h>

inherit MONSTER;
void create()
{
        ::create();
        set_level(17);
        set_name( "wild cat", "ɽè" );
        add("id",({"cat"}));
        set_short( "ɽè" );
        set_long(@C_LONG
����һֻ����Ư��Ƥë�Ķ������������������ƺ�û��ʲ��Σ���ԡ�����ɭ���е�
�����ƺ������ҿ�����������С��һ��ĺá�
C_LONG
        );
        set("unit","ֻ");
        set_perm_stat( "str", 23 );
        set_perm_stat( "dex", 25 );
        set_perm_stat( "int", 13 );
        set_perm_stat( "kar", 20 );
        set_skill( "dodge", 100 );
        set("max_hp", 550);
        set("hit_points", 550);
        set("special_defense", ([ "all":50, "none":25,"fire":5 ]) );
        set("aim_difficulty",
            ([ "vascular":10,"weakest":30 ]));
        set( "killer", 1 );
        set( "c_killer_msg","��ͻȻ����ɽè���Ӷ�������צ���㱳�����˹���....");
        set( "alignment", -500 );
        set_natural_weapon(50,22,30);
        set_natural_armor(80,1);
        set_c_verbs( ({ "%s�Ӷ�������צ����%sץȥ", "%sѸ�ٵ���%s��ȥ" }) );
        set_c_limbs( ({ "ͷ��", "����", "�Ų�" }) );
}
