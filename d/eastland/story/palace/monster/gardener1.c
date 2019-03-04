#include <mudlib.h>
#include "../../story.h"
inherit MONSTER ;
void create ()
{
	::create();
	set_level(16);
	set_name( "gardener", "��Ӣ" );
	add ("id", ({"gardener"}) );
	set_short( "�Ứ԰������ ��Ӣ");
	set_long(@CLONG
��Ӣ����һ��������ӡ��˵��������ϳ���һ�Գ��ͨ�����ϻ����ơ���������
�ڿ��У������ĺ������������Ľк�����Ӣ���ǹ����Ứ԰������ò�Ҫ�ڴ˴���
�£������⵽���ĳͷ����� 
CLONG
	);
	set("race","god");
	set("gender","male");
	set_perm_stat("str", 27 );
	set( "alignment", 100 );
        set( "max_fp",200);
	set_natural_weapon( 5, 4, 10 );
	set_natural_armor( 68, 30 );
        set_skill("dodge",70);
        set_skill("parry",70);
        set_skill("shortblade",100);
        wield_weapon(SPWEA"scissors");
        equip_armor(SPARM"gardener_belt");
        set("Hking",1);
        set("special_defense",(["all":30,"none":25]));
}
void init()
{
   if ( this_player()->query_temp("kill_huang") ) {
      write("��Ӣ�ߵ��������ڻ�԰��������������Ҳ��úý�ѵ��Ź�������\n\n");
      kill_ob(this_player());
      this_player()->delete_temp("kill_huang");
   }
   ::init();
}