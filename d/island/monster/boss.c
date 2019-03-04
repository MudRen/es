#include "../island.h"

inherit MONSTER;

void create()
{
    ::create();
    set_level(5);
    set_name( "Boss", "���ϰ�" );
    set_short( "���ϰ�");
    set_long(@LONG
�������ſ�ջ�ĵ��ϰ壬��ɱ�С����Ŷ�������ǳ���(cooking)һ��Ŷ��
LONG
            );
    set("unit","λ");
    set("race","lizardman");      
    set("age",50);
    set("gender","male" );
    set("alignment",200);
    set("weight",300);
    set("wealth/copper",150);
    set_perm_stat("str",5);
    set_perm_stat("dex",5);
    set_perm_stat("kar",5);
    set_perm_stat("int",5);
    set_perm_stat("pie",5);
    set("hit_points",100);
    set("max_hp",100);
    set_natural_armor(25,7);
    set_natural_weapon(15,0,5);
    set("inquiry",([
        "cooking":"@@ask_cooking"]) );
    set("exp_reward",200);
}

int accept_item(object player,object ob)
{
      string *name;
      object obj;
      name = ob->query("id");
      
      if( name[0] != ("shark's fin") ){
      tell_room(environment(),@LONG
���ϰ��������˵:��������������һ�Ķ���������δ��̫�����ҵĳ����˰ɣ���
LONG
      );
      command("drop " + name[0] );
      return 1;
      }  
      tell_room( environment(),@LONG
���ϰ�ܸ��˵�˵:�ۣ������õ���ỹ�ǵ�һ�ο���������ģ����ҵģ�
������������ˮ������һ�£�һ��������������ͳ���������ǰ�ˣ���
LONG
      );
      ob->remove();
      obj = new(IOBJ"soup");
      obj->move(environment(player));
      return 1;
}
 
 
void ask_cooking()
{
    write(@ALONG
���ϰ�ң����Զ����˵��:�����ҳ�ƨ�����κζ������������У�������
��ζ�ļ���Ŷ����

*******����������������ӿ�����������˻���Ŷ��̫�������ˣ���*******
ALONG
        );
	return;
}
