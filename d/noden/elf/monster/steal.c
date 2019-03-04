#include "../layuter.h"
#include "/include/move.h"

inherit MONSTER;

void create()
{
        ::create();
        set_level(15);
        set_name( "thiris", "ϯ��˹" );
        add ("id", ({ "thief", "daemon","thiris" }) );
        set_short( "ϯ��˹" );
        set("unit","λ");
        set_long(
           " ���ǵ���ħ���־����ʱ�������Թ��Ĳд��ħ���ˣ���һλ�ɶ��С͵��\n"
        );
        set("alignment",-1000);
        set("wealth/gold",20);
        set_perm_stat("str", 20);
        set_perm_stat("dex", 30);
        set_perm_stat("kar",30);
        set_natural_weapon( 15, 10, 28 );
        set_natural_armor( 70, 20 );
        set ("gender", "male");
        set ("race", "daemon");
        set_c_limbs(({"����","ͷ��","�Ų�","�ֱ�"}));
        wield_weapon(LWEAPON"daemon_dagger");
        equip_armor(LARMOR"daemon_amulet");
}

void die()
{  
   object ob1,killer;
   
   ob1 = new(LARMOR"statue");
   killer = query("last_attacker");
   if( !killer ) {
     ::die();
     return;
   }
   tell_room( environment(this_object()),
      "\n\nϯ��˹��΢��������˵����������ǰ������\��Ļ��£�͵�˷ǳ���Ķ���\n"
      "������������Թ������ʧ�޶��������ƶ�����ȥ���˺ü��ʣ�������һ�������Һ�ϲ��\n"
      "��������˵����ԭ������Ϊ������������跹��˼���Һܹ��ⲻȥ��ϣ�����ܰ��һ�����\n"
      "�����������յ����ԣ�ϣ���������ɡ�\n\n"
      "������Ӵ������ó�һ��������㡣\n"
      "����˵��˶λ�, ����������һ������Ѽ��ˡ�\n" );
   ob1->set("killer",(string)killer->query("name"));
   if( (int)(ob1->move(killer)) != MOVE_OK )
		ob1->move(environment(this_object()));  
   ::die();   
}
