#include "../asterism.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(14);
	set_name( "Andromeda", "����¶���" );
	add("id",({"administrater","halfling","andromeda"}) );
   set_short( "ͼ��ݹݳ�����¶���" );
	set_long(
		"���¾�Ȼ�����������ľ�����Ů !! ��Ȼ�������С��һ��,\n"
                "����ȴ������������Ů���������ġ���������������ʱ,\n"
                "��ͻȻ̧ͷ���˿���,����Ц��Ц��\n"
	);
	set( "gender", "female" );
	set( "race", "halfling" );
	set( "alignment", 450 );
	set( "time_to_heal", 7 );
	set_natural_armor( 56, 12 );
	set_natural_weapon( 17 , 5 , 8 );
	set("max_hp",350);
	set("hit_points",350);
        set("inquiry",([         
                         "�Ų��޻�": "@@quest1a",
                      ]) ) ;

	set_perm_stat( "kar", 24 );
	set( "wealth/gold", 30 );
	set( "special_defense", ([ "all": 12 ]) );


}

void quest1a(object who)
{
   int a,b ;
   string cmsg,msg ;
     
   a = this_player()->query("astr/questa");
   b = this_player()->query_temp("astr/quest1");
      
   if(!a || !b || b < 3 )
      return notify_fail(can_read_chinese()?
             "����˵ʲ�� ?? ��һ�䶼��������\n" :
             ""  ) ;
   

        who->set_temp("astr/quest1",41);  
        cmsg =
            "����¶���������������˵�� :\n"
            "      �ҼǵùݲصĲ�������һ����춺������ܵ�,\n"
            "      ��ȥ���ҿ�,Ҳ�����Щ������\n" ;
        msg  = "" ;
            
   write(can_read_chinese()?
           cmsg : msg );
   return ;
}


