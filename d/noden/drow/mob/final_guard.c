#include "../iigima.h"

inherit MONSTER ;

void create ()
{

        ::create();
        set_level(11);
        set_name( "Final guard","��������" );
        add ("id", ({ "drow", "guard" }) );
        set_short( "Final guard","��������" );
        set("unit","λ");
        set_long(
@C_LONG
��λ�Ǽ��ӽ���֮�ص���������춴˴�ֻ��ÿ�����ʱ������ٿ���
��ƽʱ���ɴ����Ž������ϣ��������Ǹ��𿴹ܴ˵ص��ˡ�����
C_LONG
        );
        set_perm_stat("str", 15);
        set_perm_stat("dex", 14);
        set ("natural_weapon_class1", 15);
        set("alignment",600);
        set ("natural_min_damage1", 3);
        set ("natural_max_damage1", 6);
        set ("natural_armor_class", 40);
   set( "special_defense", ([
      "all":15,"fire":-10,"cold":-10,"evil":30,"divine":-30,"none":5 ]) );
        set ("gender", "male");
        set("wealth/copper",2000);
   set ("weight" , 600 );
        set ("race", "drow");
        set_c_verbs(({"%��%s��%s��ȥ","��%s��%s��ȥ"}));
        set_c_limbs(({"����","ͷ��","�Ų�","�ֱ�"}));
        wield_weapon(OBJ"copper_lb");
        equip_armor(ARM"shield");
        equip_armor(ARM"plate");
        equip_armor(ARM"ring1");
}

