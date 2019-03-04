#include "../takeda.h"
#include "/include/move.h"

inherit MONSTER;

void create()
{
        ::create();
        set_level(19);
        set_name( "shell", "ǧ���ϰ�" );
        add ("id", ({ "shell" }) );
        set_short( "ǧ���ϰ�");
        set("unit","��");
        set_long(
           "    �㿴��һ���ǳ��޴�İ����ֲڵ���Ǿ���ͬʯͷ���Ӳ�����泤��\n"
           "����\��ˮ�����࣬ʹ�㿴����ԭ������·������Ƭ���ǵĽӷ촦������͸\n"
           "��һ�ɵ����ı��⡣\n"
        );
        set( "likefish",1);
        set( "unbleeding",1);
        set( "max_hp",700 );
        set( "hit_points",500 );
        set("alignment",200);
        set_perm_stat("str", 28);
        set_perm_stat("dex", 25);
        set_perm_stat("kar",27);
        set_natural_weapon( 50, 30, 50 );
        set_natural_armor( 150, 65 );
        set ("gender", "male");
        set ("race", "monster");
        set_c_limbs(({"Ӳ��"}));
        set_c_verbs( ({"%s��������ˮ��һƬ������ȻϮ��%s","%s����������һ������ɳʯ��Ȼ����%s","%s�򿪰��ǣ�һ�����Ⲣ��������%s","%s��Ӳ�ǽ�����ס%s","%s��ˮ�����һ��ǿ��ˮ��������%s"}));
}

void die()
{  
   object ob1,killer;
   
   ob1 = new(TOBJ"pearl");
   killer = query("last_attacker");
   if( !killer ) {
     ::die();
     return;
   }
   tell_room(environment(this_object()),
      "\n�������һ�������������Ӳ�İ��ǣ�ʹ���ܹ���������ǵ��ڲ�\n\n\n\n"
      "���ڰ����ڷ��ֵ�һ���൱�������������ӣ������������Ĺ�â���㿴\n"
      "�ĺϲ�£�죬�������ֽ�ȥ�������ͳ�����\n",
      this_object());
   if( (int)(ob1->move(killer)) != MOVE_OK )
		ob1->move(environment(this_object()));  
   ::die();   
}
