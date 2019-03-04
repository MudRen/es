#include "../takeda.h"
#include "/include/move.h"

inherit MONSTER;

void create()
{
        ::create();
        set_level(15);
        set_name( "gorden dreaming carp", "�ƽ��λ�����" );
        add ("id", ({ "fish","carp" }) );
        set_short( "�ƽ��λ�����");
        set("unit","β");
        set_long(
           "    �ۣ���Ư����һ������ѽ���ƽ�ɫ����Ƭ��ҫ����Ŀ�Ĺ�â������\n"
           "���Ǵ����ſ�����˵�Ļƽ��λ�����ɡ�\n"
        );
        set( "likefish",1);
        set( "unbleeding",1);
        set( "max_hp",300 );
        set( "hit_points",300 );
        set("alignment",200);
        set_perm_stat("str", 18);
        set_perm_stat("dex", 22);
        set_perm_stat("kar",15);
        set_natural_weapon( 30, 20, 35 );
        set_natural_armor( 50, 30 );
        set ("gender", "male");
        set_c_limbs(({"ͷ��","����","β��"}));
        set_c_verbs( ({ "%s���죬��%sҧȥ","%sβ������һ˦��˦��%s" }) );
}

void die()
{  
   object ob1,killer;
   
   ob1 = new(TOBJ"sashimi");
   killer = query("last_attacker");
   if( !killer ) {
     ::die(1);
     return;
   }
   tell_room(environment(this_object()),
      "\n�������һ����춴�����������Ե������ͷ���������ϴӴ�������һ��\n"
      "�λûƽ������ˣ�Ϊ�˼�������������㣬�����������ϵ������������\n"
      "��������Ƭ������˳�ְ�ʣ�µġ������ڸ����ĵ��ϣ�������ݡ�\n",
      this_object());
   if( (int)(ob1->move(killer)) != MOVE_OK )
		ob1->move(environment(this_object()));  
   ::die(1);   
}
