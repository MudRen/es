#include "../iigima.h"

inherit MONSTER ;

void create ()
{
        ::create();
        set_level(10);
        set_name( "Drow soldier","�ڰ�����ʿ��" );
        add ("id", ({ "drow", "soldier" }) );
        set_short( "Drow soldier","�ڰ�����ʿ��" );
        set("unit","λ");
        set_long(
@C_LONG
���Ǻڰ�������ʿ����Ҳ�Ǻڰ������Ƿ���������������������
��Ϊ�м���Ĵ�䣬���Ƕ��Ʒ�������֮�أ���ֹ���ⷢ����������������
�������ޱ����վ����
C_LONG
        );
        set_perm_stat("str", 15);
        set_perm_stat("dex", 14);
        set ("natural_weapon_class1", 18);
        set ("natural_min_damage1", 8);
        set ("natural_max_damage1", 18);
        set ("natural_armor_class", 42);
   set( "special_defense", ([
      "all":15,"fire":-10,"cold":-10,"evil":30,"divine":-30,"none":5 ]) );
        set ("gender", "male");
        set("wealth/copper",500);
   set("weight", 500);
        set ("race", "drow");
        set_c_verbs(({"%��%s��%s��ȥ","��%s��%s��ȥ"}));
        set_c_limbs(({"����","ͷ��","�ֱ�"}));
        wield_weapon(OBJ"copper_sword");
        equip_armor(ARM"shield");
        equip_armor("/d/eastland/easta/obj/brass_helm");
        equip_armor(ARM"copper_arm");
}

