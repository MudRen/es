
#include "../iigima.h"

inherit MONSTER ;

void create ()
{
        ::create();
        set_level(18);
        set_name( "Knight Perotice","Ů��ʿ���ܵ�˿" );
        add ("id", ({ "drow", "knight","perotice" }) );
        set_short( "Ů��ʿ���ܵ�˿" );
        set("unit","λ");
        set("alignment",1300);
        set("weight",600);
        set("wealth/copper",12000);
        set_long(
@C_LONG
������������һͷ����ɫ�ĳ����������Ǵ�˵սʿ�����Ǵ�����ᣬ
Ůսʿ���ܵ�˿����춳����˸߹��������Ѫͳ��������С��������
�ӳ��޿�˼��������ֵĸ���ս����֪ʶ�Ľ�����ʹ�������������
���ˣ���Ϊ�ڰ����������߹󣬲�Ҳ����ǿ������������������
�(sister)�ƺ�ʧ���ˣ�����԰�ס����
C_LONG
        );
        set_perm_stat("dex", 23);
        set_perm_stat("str",26);
        set("max_hp",800);
        set("hit_points",800);
        set("max_sp",600);
        set("spell_points",600);
   set( "max_tp", 1000 );
   set( "talk_points", 1000 );
        set("natural_defense_bonus",30);
        set("natural_weapon_class1",28);
        set ("natural_min_damage1", 18);
        set ("natural_max_damage1", 28);
        set ("natural_armor_class",60);
  set ("special_defense",(["all":60,"divine":10,"fire":30,"cold":50,"none":30]));
   set( "aim_difficulty", ([
        "ganglion" : 45, "vascular" : 40 ]) );
        set ("race", "drow");
        set ("gender", "female");
        set ("tactic","melee");
        set_skill( "longblade", 100 );
        set_skill("dodge",85);
        set_skill("parry",80);

        set_skill("block",85);
        set_skill("tactic",70);
        set( "tactic_func", "call_help" );
        set_c_limbs(({"����","ͷ��","�Ų�","�ֱ�"}));

        wield_weapon(OBJ"god2");
        equip_armor(ARM"sai_shield");
        equip_armor(ARM"earing");
        equip_armor(ARM"finger");
        equip_armor(ARM"gloves");
        equip_armor(ARM"necklace");
}
int call_help()
{
   object mob1, mob2, victim;
   int hp;

   victim = query_attacker();
   hp = this_object()->query("hit_points");

   if( hp>180 ) return 0;
   if( random(10)> 2 ) return 0;
  if( present("monster", environment(this_object())) ) return 0;
   tell_room( environment(this_object()),
 "���ܵ�˿�ġ�����Ļƻ衻�ķ�ӡ֮��ͻȻ�ٻ����ڰ����ޱ������ˣ�\n\n" );
   mob1 = new(DRO"d_monster");
   mob2 = new(DRO"d_monster");
   mob1->move(environment(this_object()));
   mob2->move(environment(this_object()));
   mob1->kill_ob(victim);
   mob2->kill_ob(victim);
   return 1;
}
