#include <mudlib.h>
#define MSPECIAL "/u/m/mercury/obj/special";

inherit MSPECIAL 

void create()
{
        set_name( " ", "  ");
        add ("id",({ "dagger"}) );
        set_short( "  ");
        set("unit", "��");
        set_long(
            
            " !!!!\n"
        );
        set( "type","dagger");
        set("weapon_class",30);
        set("min_damage",15);
        set("max_damage",30);
        set("special_attack",(["damage_type" : "cold","main_damage" : 18 ,
                                "random_damage" : 22  ,"hit_rate" : 20 ]) );

//        set("hit_func","special_attack");
        set("wield_func","wield_dagger");
        set("unwield_func","unwield_dagger");
        set( "weight", 100 );
         
   set("c_msg","\n������ ***���ӻ�ͷ*** һ������Ϊ����������ȥ!!\n\n");
   set("c_enemy_msg","\n��������� ***���ӻ�ͷ*** ��ֻ��һ�����α�������Ϯ��!!\n\n");
   set("c_fail_msg","\n����������һƬ����ĺ�����ȴ�������Լ� ! \n\n");
   set("c_fail_room_msg","���������һƬ����ĺ�����ȴ�������Լ� ! \n\n");
   }

 int fail_to_use()
 {
      if ( (string)this_player()->query("gender")=="female")
              return 0;
          else
              return 1;
}

void unwield_ferule()
{
 if(query("form"))
        {
        set( "weapon_class", 15 );
        set( "min_damage", 10);
        set( "max_damage", 20);
        tell_room( environment(this_player()), ({
        this_player()->query("c_name")+"�ı�����߹�â��ȥ�����ƽ��������.......\n"
        }), ({this_player()}) );
        tell_object( this_player(),
         "��ı�����������ȥ�����ƽ��������............\n"
                );

        set_name( "silver ferule", "�����");
        set_short( "silver ferule", "�����");
        set("form",0);
                return ;
        }
        return ;
}

void wield_ferule()
{
        int pi,iq,i ;

        if ( (string)this_player()->query("class")=="healer")
        {
        pi=this_player()->query_perm_stat("pie");
        iq=this_player()->query_perm_stat("int");
        i = (pi+iq)/2+random(20);
        set("weapon_class",30);
        set("min_damage",15);
        set("max_damage", i );
        tell_room( environment(this_player()), ({
         this_player()->query("c_cap_name")+"������߷���һ���â���������ֽ�ϣ�����������һ���ݡ�\n"
        }), ({this_player()}) );
        tell_object( this_player(),
         "��Ľ�߷������ɹ�â�����һ�Ѿ�Ө��͸�����........��\n"
                );
        set_name( "cold ferule", "�������");
        set_short( "cold gerule", "�������");
        set("form",1);
                return ;
        }
}
 
