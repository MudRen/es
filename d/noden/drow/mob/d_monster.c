#include "../iigima.h"
inherit MONSTER ;
void create ()
{
        ::create();
        set_level(13);
        set_name( "Dark monster","�ڰ�����" );
        add ("id", ({ "monster" }) );
        set_short( "�ڰ�����" );
        set("unit","ֻ");
        set_long(
@C_LONG
����һֻ�����ܵ�˿���񽣡�����Ļƻ衻���ٻ������ޣ�����
������Ŀ����㣡
C_LONG
        );
        set_perm_stat("str", 22);
        set_perm_stat("kar",20);
        set("alignment",180);
        set("killer",1);
        set_skill("dodge",60);
        set ("natural_weapon_class1", 20);
        set ("natural_min_damage1", 20);
        set ("natural_max_damage1", 35);
        set ("natural_armor_class", 50);
        set("natural_defense_bonus",16);
}

