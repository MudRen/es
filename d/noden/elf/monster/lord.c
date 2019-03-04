
#include "../layuter.h"

inherit MONSTER;

void create ()
{
        ::create();
        set_level(19);
        set_name( "Elf Lord", "������" );
        add ("id", ({ "elf", "lord" }) );
        set_short( "������" );
        set("unit","λ");
   set_long( @LONG
�������Ǿ������쵼��, �����ݾ����ĸ������ʹ�þ���
���ܹ���ʦ��ְ�����������ذѾ���彨����Ϊһ��������ʳ
��������Դ, ��������������ʱ, ����ת�����һλ�ֲ���ս
ʿ���������������ʱ������һ�ѡ���̫���齣��, �����
Խ�������˶���Ϊ��ǿ֮սʿ�������������ι���֮�游����
��������������ŵ������֮Ĭ��˹��������, ����ѫ��ս������
LONG );
        set("alignment",500);
        set("wealth/gold",20);
        set_perm_stat("int",30);
        set_perm_stat("str", 30);
        set_perm_stat("dex", 20);
        set_perm_stat("kar",30);
        set_natural_weapon( 20, 10, 35 );
        set_natural_armor( 40, 40 );
        set ("gender", "male");
   set( "max_hp", 1110 );
   set( "hit_points", 1110 );
        set ("aim_difficult",(["critical":50, "vascular":20, ]));
        set ("special_defense",
          (["all":60,"fire":35,"poison":15,"none":25]));
        set ("race", "elf");
        set_c_verbs(({"��%s��%s��ȥ","��%sʹ����ɱһ����%s����","��%s��%s��ȥ"}));
        set_c_limbs(({"����","ͷ��","�Ų�","�ֱ�"}));
       
        set_skill("parry",100);
        set_skill("block",100);
        set_skill("longblade",100);
   set( "war_score", 1000000 );
        
        wield_weapon(LWEAPON"sword");
        equip_armor(LARMOR"boots");
        equip_armor(LARMOR"glove");
        equip_armor(LARMOR"shield");
        equip_armor(LARMOR"legging");
        equip_armor(LARMOR"plate");
        equip_armor(LARMOR"cloak");
}

void die()
{
   object scroll;

   scroll = new( "/d/mage/tower/obj/eb8_scroll" );
   scroll->move(environment(this_object()));

   tell_room( environment(this_object()),
     "���ˡ���һ��, һ�������Ӿ����������������ڵ��ϡ�\n",
     this_object() );
   ::die(1);
}
