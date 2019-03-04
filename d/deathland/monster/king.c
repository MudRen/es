#include "/d/deathland/echobomber.h"

inherit MONSTER;

void create()
{
	::create();
	seteuid(getuid());
	set_level(19);
	set_name( "Dwarf King Molader V", "���˹���Ī��������" );
	add ("id", ({ "king", "molader", "dwarf", }) );
	set_short( "���˹���Ī��������" );
	set_long(@DESC
���˹���Ī��������,����������Ȼ����,��������������ս�����ɻ�����һ������.
�����εİ�������˵�ս��֮��,���쵼����������˾��˵Ĺ���,���������Լ���
��а��ľ�����ս����ȥ.
DESC
	);
    set("weapon_master",1);
    set( "alignment",1600);
    set( "gender", "male" );
    set( "race", "dwarf" );
    set( "unit", "��" );
	set_perm_stat( "dex", 23 );
	set_perm_stat( "str", 27 );
	set_perm_stat( "int", 21 );
	set_perm_stat( "con", 30 );
	set_perm_stat( "piety", 15);
	set_perm_stat( "karma", 30);
	set_skill("longblade",100);
	set_skill("parry",100);
        set("special_defense", (["all":35,"none":60,"monk":20,"scholar":20]) );
	set ("max_hp", 999);
	set ("hit_points", 999);
	set ("wealth", ([ "gold": 5 ]) );
	set_natural_weapon( 25, 5, 45 );
	set_natural_armor( 50, 60 );
    set ("weight", 400);
    set( "inquiry", ([
         "troll" : "@@ask_troll" ,
         "valor" : "@@ask_valor" ,
         "queen" : "@@ask_queen" ,  
           ]) );
    set ("unbleeding",1);
    set ("chat_chance", 8);
	set ("chat_output", ({    "���˹���Ī��������ϣ��һ��ΰ�������(valor)�Ӿ���(troll)���������������Ĺ���\n",
	    }) ); 
	set ("att_chat_output", ({	    "����˵:�޴��ļһ�,�㲻���ܻ����ҵ�\n",
	    }) );
	wield_weapon(Weapon"/blacksword");
    equip_armor(Armour"/leggings02");
    equip_armor(Armour"/helmet02");
    equip_armor(Armour"/boots02");
    equip_armor(Armour"/plate03");
}

void ask_troll( object who )
{
        tell_object( who,@MSG1
����,�к�ǿ��������,���ǰ������Ѿ���������ս��������
�������֪�����꾡������,����\����ս���о��ҵĿ���(Karl)����
�ܸ�����.
MSG1
);
      return ;        
}

void ask_valor(object who)
{
      
      tell_object(who,
      "������Ҫһ�������������Կ�����(troll),�����Ը�������������ȥ�ҿ�������\n");
      return ;
}

void ask_queen(object who)
{
     object *items,special;
     int i;
     
     tell_object(who, @ASK_QUEEN_1
����˵:��!!�Դ��ҵĴ���ӷ�����������֮��, ������Ҳû��¶��Ц����. 
��ҲȰ��������Ҫ��ÿ�һЩ, ���������޷�ֹͣ����. ��Ҳ�����������
�����Ѱ�������Ȱ����, Ȼ�����޷�ֹͣ��������.
ASK_QUEEN_1
     );
     if ( (int) who->query_level() >= 10 ) {
       items=all_inventory(who);
       for(i=0;i<sizeof(items);i++) {
         if ( (string)items[i]->query("name")== "Black Box of Molader" )
           return;
         }
       tell_object(who,@ASK_QUEEN_2
������һ���ں���, ������Ϊ�˽�����ǵ�����ʱ, �������а�����,
������, ϣ�����ܹ����հ����ʺ�ָ����յ�Ц��.
ASK_QUEEN_2
       );
       special=new(Object"/blackbox");
       
       switch ( (int)who->query_quest_level("queen_smile") ) {
         case 0: break;
         case 5: 
                 tell_object(who,"���Ѿ������������,����ں��ӵĶ��������ܹ��������.\n");
         case 4:
         case 3:  
         case 2: 
                 special->set("quest_item/crystal_card",1);
         case 1: special->set("quest_item/explorer_bell",1);
                 special->set("quest_action/invoke_bell",1);
                 tell_object(who,"������������������,��ں��ӱ�����һЩ���õ���Ʒ.\n");
         }
       special->move(who);  
       }
     return;
}

void die()
{
	object killer,scroll;
	killer = query("last_attacker");
        if (killer)
	killer->set_explore( "deathland#37" );
	 scroll = new( "/d/mage/tower/obj/star_scroll" );
   scroll->move(environment(this_object()));

   tell_room( environment(this_object()),
     "���ˡ���һ��, һ�������Ӱ��˹����Ļ������ڵ��ϡ�\n",
     this_object() );
	::die(1);
}

void show_headband(object player)
{
     object key;
     tell_object(player,@MSG2
���ǰ���������������ѧ����? ϣ�������ûʺ�����ʰ�������յ�Ц��.
������Կ��ȥ�һʺ��!
MSG2
     );
     key=new(Object"/key01");
     key->move(player);
     return ;
}
