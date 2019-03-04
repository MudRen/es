#include "../echobomber.h"

inherit MONSTER;

void create ()
{
	::create();
	seteuid( getuid() );
    set_level(15);
    set_name("Imp mage Morr","����ħ��ʦĦ��");
    add("id",({"imp","mage","morr"}) );
    set_short("Imp mage Morr","����ħ��ʦĦ��");
	set_long(@LONG
??
LONG
    ,@C_LONG
һ�����ϳ���һ�Գ�������ħ��ʦ.�ƺ�����ǿ��ķ���.
C_LONG
	);
    set("alignment",-400);
    set( "gender", "female" );
    set( "race", "imp");
    set( "unit", "��" );
    set_perm_stat( "dex",21);
    set_perm_stat( "str",11);
    set_perm_stat( "int",25);
    set_perm_stat( "con",13);
    set_perm_stat( "piety",17);
    set_perm_stat( "karma",22);
	
    set ("max_hp",340);
    set ("max_sp",1300);
    set ("hit_points",340);
    set("spell_points",1300);
    set ("wealth", ([ "gold":21]) );
    set_natural_weapon(22,12,17);
	set_natural_armor(65,24);
    set ("weight", 160);
    set_skill("target",100);
    set_skill("elemental",100);
    set_skill("concentrate",100);
    set_skill("dodge",98);
    set_skill("wand",100);
    set("magic_delay",2);
    set("spells/sleet",4);
    set("spells/fireball",4);
      set( "inquiry", ([
         "rune" : "@@ask_rune",
         "bottle" : "@@ask_bottle",
         "painting" : "@@ask_painting",
         "chichikair":"@@ask_chichikair",
         "book":"@@ask_book",
         "charge":"@@ask_charge",
         ]) );
    set("special_defense", (["all":35,"none":10]) ); 
    set ("aim_difficulty",(["vascular":20]) );
    set( "tactic_func", "cast_spell");
    wield_weapon(Weapon"/wand");
}

void ask_rune(object who)
{
     tell_object( who ,@MSG1
��Щħ���鼮�ϼ����������ٻ�а������ķ���,���������Щ����ʵ����̫����.
����Ŀǰ��Ҳֻ���ٻ�����Ӱ��������,ֻ�����Ҳ�û�а����ܿ���ס��.
MSG1
       );    
}

void ask_bottle(object who)
{
     object *items;
     int i;
     
     tell_object( who,@MSG2
���ƿ�����ҵ���ʦ���ҵ�,���ħ��ƿ....
�ٺ�,����һ������.
MSG2
                 );
     items=all_inventory(who);
     for(i=0;i<sizeof(items);i++) 
        if ( (string)items[i]->query("name")== "Black Box of Molader" )
           if (items[i]->query("quest_action/find_book")) {
              tell_object( who,@MSG3
���Ǽ�Ȼ������û����Ȿ�о��ĵ�, ���������Ҳ�޷� : 
����һ������ƿ, ���ܹ������˵�����������, ������� 
��ʹ������ƿ��ʱ��, ʹ���߱�����Լ���������ע����� 
, ���ͨ��������ע�����, ���������ƿ�Ѿ����ҵ����� 
����������, �����㲻��ʹ�� ,������ҵ�������ƿ, ��� 
������, ���ܹ�ע��(charge)���������������ʹ���� .
MSG3
                 );
           } 
      return;           
}

void ask_painting(object who)
{
     tell_object( who,"Ħ���ش���:ϲ���ҵ��Ի�����?\n");

}

void ask_chichikair(object who)
{
     tell_object(who,@MSG4
Ħ��˵: ���濭��, ԭ�������ǰ���ħ���о�С���������ĵõ�һλ�߼�ħ��ʦ ,
�벻����������˷��. ��͵�����������������о��ĵ�, ������ܹ�������
���Ǳ��о��ĵ�(book), �����һ�ܸм���� .
MSG4
                 );
}

void ask_charge(object who)
{
     object *items;
     int i;
     
     items=all_inventory(who);
     for(i=0;i<sizeof(items);i++) 
        if ( (string)items[i]->query("name")== "Black Box of Molader" ) 
          if ( items[i]->query("quest_action/find_book") ) { 
          if ( items[i]->query("quest_item/ancient_bottle") ) {
          tell_object(who,@MSG5
�ҽ��������е�������������.....
Ħ����ʼ���������д�..
��
��
��
ħ
��
ħ
ƿ
��
Ҫ
��
��
��
��
��
һ��ҫ�۵Ĺ�â�����������.
��ʱĦ��˵:
���Ѿ�����ʹ��������ƿ��.
MSG5
          );
          items[i]->set("quest_action/charge_bottle",1);
          if ( (int)who->query_quest_level("queen_smile") < 3 ) 
             who->finish_quest( "queen_smile" , 3 );
          }
          else 
          tell_object(who,"���ҳ�����ƿ��.\n");
          return;          
          }
     tell_object(who,"Ħ������ֵ���������.\n");
     return;     
}
void ask_book(object who)
{
     object *items;
     int i;
     
     items=all_inventory(who);
     for(i=0;i<sizeof(items);i++) 
        if ( (string)items[i]->query("name")== "Black Box of Molader" ) 
          if ( items[i]->query("quest_item/study_book") ) { 
          tell_object(who,@MSG6
���ҵ��ҵ�����.лл��.
Ħ���û������鲢˵:лл,�������Ҫ������
��, ���ܿ���.
MSG6
          );
          items[i]->set("quest_item/study_book",0);
          items[i]->set("quest_action/find_book",1);
          return;
          }
     tell_object(who,"���Ƕ�����о��ĵ�,�Ѿ���ʧ��, ϣ�����ܰ����һ���.\n");
     return;
}

int cast_spell()
{
    object victim;
    string name;
    if( !(victim = query_attacker()) ) return 0;
    
    name = victim->query("name");
    
    if( random(10) < 3 ) {
      command("cast sleet on "+name);
      return 1;
     }
    else if (random(10)< 2) {
      command("cast fireball on "+name);
      return 1;
      }
    else return 0;   
}

