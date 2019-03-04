#include "../echobomber.h"

inherit MONSTER;

void create ()
{

	::create();
    set_level(12);
    set_name("dwarf guard","��������");
    add ("id", ({ "guard","dwarf"}) );
    set_short( "a dwarf guard",
           "��������");
	set_long(@LONG
������������������ڰ��˴�ׯ�����,�������ƺ����������뿪���ﵽ
�ư�(Pub)ȥ.
LONG
	);
    set("alignment",-300);
    set( "gender", "male" );
    set( "race", "dwarf");
    set( "unit", "��" );
    set_perm_stat( "dex",  13);
    set_perm_stat( "str",  17);
    set_perm_stat( "int",   8);
    set_perm_stat( "piety", 8);
    set_perm_stat( "karma",15);
	set_skill("shortblade",78);
	set_skill("parry",55);
    set ("max_hp",390);
    set ("max_sp",0);
    set ("hit_points",350);
    set ("spell_points",0);
    set ("wealth", ([ "gold":13]) );
    set_natural_weapon(27,15,25);
	set_natural_armor(43,19);
    set ("weight", 350);
    set ("inquiry",([
         "pub":"@@ask_pub",
         "wine":"@@ask_wine",
         "maze":"@@ask_maze",
        ]) );
    
    set("chat_chance",10);
    set("chat_output",({
        "��������Ҫ˯�������ڸ�λ����������ú�����.\n",
        "����˵:��ʹ����ʧ���Թ�(maze)��,�������Ĳ���Ϳ����뿪��.\n"
       }) );
    equip_armor(Armour"/ringmail01");
    wield_weapon(Weapon"/shortsword02");
    equip_armor(Armour"/armband01");
     
}

void ask_pub(object who)
{
  tell_object(who,@MSG1
����˵:������վ�ڵ�ʱ��,��Ҫ��������ư�,�ǻ��������������ơ��(wine),
��������һ�ڿ�ˮ.
MSG1
   );

}

void ask_wine(object who)
{
   tell_object(who,@MSG2
ơ��,�ɶ�,������վ�ڵ�ʱ��,��Ҫ���������,�һ��̲�ס��Ҫ͵��,��������Υ
�����ɵ�.����������˵

����һЩ��֭����������ҽ���.����������һ�ڿ�ˮ.
MSG2
   );
}

void ask_maze(object who)
{
   tell_object(who,@MSG3
����˵:���Թ��Ѿ�����������\���,�ڶ�εİ��˾���ս����,���������޷�
ͻ��������һ������.����Թ���ħ���ϱڲ�����һ�����ܽ⿪��.��!��!
MSG3
   );
}

int accept_item(object ob1,object ob2)
{
    if ( !( ob2->id("juice") ) )
      return 0;
    else
      {
      tell_object(environment(),@MSG4
����˵:лл.
�����ܿ�ذѹ�֭���ɾƵغ�������Ȼ���������������
����������ط���ʵ���ֲ���, �����в�֪��������������ֵֹĶ���
�ܳ���, ���ҵص׳�����һЩĪ���������������, �����Ҿ��úܿ���
����һ���пյ�ʱ��, �Ҿͻᵽ�ư�ȥ�Ⱦ�����, ��֪���ưɰ�, �Ƕ�
�ľƱ��Ǹ�����Ȥ�ļһ�, ��֪����\��\���Ĵ�������(rumors).
MSG4
       );
      ob1->set_explore("deathland#36");
      ob2->remove();
      return 1;
      }
}
