#include <mudlib.h>      
        
inherit WEAPON;
        
void create()
{        
     set_name("silver axe","����");
     add("id",({"silver","axe"}) );
     set_short("����");
     set_long(@C_LONG
����һ��С�ɾ��µ�����������
C_LONG
     );
     set("unit","��");
     setup_weapon( "axe", 45, 30, 47 );
     set( "weight", 250 );
     set("second",1);
     set( "value", ({ 2800, "silver" }) );
}
int stop_wield()
{
     object holder;
     int my_ali;
     holder = this_player();
     my_ali = (int)holder->query("alignment");
     if (my_ali > 6000 )
        return 0;
     else {
        notify_fail(
          "�㻹��������ʹ�������������ָ�ӣ������ղ�ס����\n\n");
        return 1;
     }
}                                                                                                                                                                       