#include <mudlib.h>
inherit WEAPON;

#define NEED_ALIGNMENT 6000

void create()
{
    set_name("small dagger","СС����");
    add("id",({"dagger","needle"}) );
    set_short("СС����");
    set_long(@C_LONG
СС�����ǡ�һ����ҽ Сѩ�ӡ��������Ʋ����õġ���ͨ�崿��,�����ұ�,����
�������,����������ˡ��β����ٺò����ˡ��ഫСС��������������ʮ������
��,����������ʮ�����Ծ������ƶ���,��Ȼ�����ѵĹ��̺ƴ�,�����ͱ���������
��������,ȴҲ��ֵ�õġ� 
C_LONG
       );
    set("unit","��");
    setup_weapon( "dagger", 40, 1, 1 );
    set("weight",40);
    set("value",({150,"gold"}));
    set( "wield_func","wield_dagger");
    set( "unwield_func","unwield_dagger");
}

int stop_wield()
{
     object holder;
     int my_ali;
         holder = this_player();
         my_ali = (int)holder->query("alignment");
         if (my_ali > NEED_ALIGNMENT )
            return 0;
         else {
               notify_fail(
                   "�㻹��������ʹ��СС���벻�����ָ�ӣ������ղ�ס����\n\n"
                                                  );
               return 1; 
          }
}

int wield_dagger()
{
   int my_int;
   
   my_int=this_player()->query_perm_stat("int");
   set( "min_damage",my_int);
   set( "max_damage",my_int+10);
     return 1;
}
                  
int unwield_dagger()
{
   set( "min_damage",1);
   set( "max_damage",1);
     return 1;
}
