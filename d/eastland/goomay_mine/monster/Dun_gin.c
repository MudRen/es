
#include <../zeus.h>
inherit MONSTER;

void create()
{
        ::create();
        set_level(19);
        set_name( "dun gin", "����" );
        add("id",({"dun","gin"}));
        set_short( "����");
        set("unit","λ");
        set_long( @LONG
������һλ����������ˣ������������߽�����ʱ�������˲��ٵ���
С����ʵ��������Ľ���ƽ����һ��ʱ�䣬����Ӣ���ѹ����˹����
�ϲԵ�׽Ū������ĺ�������������Ǩŭ�����һ����ޣ���������
���֮�ʣ���Ȼ�˳����������μң�ն��һ����˿�ľ������������飮
LONG
        );
        set_perm_stat("str",25 );
        set_perm_stat("dex",24 );
        set_natural_weapon(40, 25, 30);
        set_natural_armor( 60, 20 );
        set( "max_hp",700);
        set( "hit_points",700);
        set ("gender", "male");
        set ("race", "dwarf");
        set_c_limbs(({"����","ͷ��","�Ų�","�ֱ�"}));
        wield_weapon(ZOBJ"/thunder_blade");
        equip_armor(ZOBJ"/white_robe");
        equip_armor(ZOBJ"/fire_cloak");
        equip_armor(ZOBJ"/six_shoe");

        set("inquiry",([
        
           "net": 
                "��Щ������������ס����������ľͷ�ģ����������ɵ�������ľͷ\n"
                "�����Ϳ�ʡ�²���ʱ�䣬����\n",     
           "river": 
                "����������ľͷ�Ĺܵ�������㲻�����Ļ���������ȥ����(swim)����\n",
           "ghost":"@@ask_ghost",
                
      ]));
}
int ask_ghost()
{   if(this_player()->query_temp("ask_ghost")){
    tell_object(this_player(),
@AA

�����й��ҿ���һ���ǿ�������̫���ˣ��������Ϸ������Ƕμ������һ
����ط����ѣ���ʲ��ô�С�ֵģ�ֻҪ���ϱߵ�ǽһ�ƾͿ��Խ�ȥ�ˣ�
ȥȥȥ���������ң�
AA
);
}else{
tell_object(this_player(),
@BB

�㲻Ҫ������������ģ�����������Ǻ�Ǭ����ร�����˵С���ң��㣡��
BB
);
}
return 1 ;
}
   