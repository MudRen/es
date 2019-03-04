
// Deathland/ruin1/ruin55.c

#include "../echobomber.h"

inherit ROOM;

void create()
{
	 ::create();
     set_short("the ruin","�ż�");
     set_long(@Long

Long
,@C_Long
һ���ƾɵ��ż� ,�����ƺ��Ѿ��ķϺܾ��� .���ϵ����ǲ�ש���� ,�����˾���
��ط��Ѿ�\��\��δ���������� .һ����ɫ��޺ֲ̦�︽�����Ե�ǽ���� ,ʹ����ط�
�����ո��Ե�ʮ�ֵĹ��� .����ط����ż��Ķ����� ,����������ط���ʱ�� ,�㷢
�������ƺ��������ֱ�ѹ�ȵĸо� ,���ָо��ƺ�������Щ�ƺ���������������ֹ�
ʯ�� ,��Щʯ��ʵ��̫������ ,�����޷����ĵش������� .
C_Long
);
     set("now_weapons",([
         "longblade": 0,
         "thrusting": 0,
         "dagger": 0,
         "shortblade": 0,
         "chain": 0,
         ]));
     set("correct_weapons",([
         "longblade": 1,
         "thrusting": 0,
         "dagger": 0,
         "shortblade": 0,
         "chain": 1,
         ]));
     set("item_func",([
         "statue":"look_statue",
         ]) );
     set("search_desc",([
          "statue":"@@search_statue",
         ]) ); 
     set("exits",([
         "southwest":Deathland"/ruin1/ruin44",
         ]) );
     
     reset();
}

int look_statue()
{

    write(can_read_chinese() ?
          "һЩ���˵�ʯ�� ,��Щʯ��ǳ��ı��� ,�������Ӿ�����������צ��������\n"
          "Ϯ .��Щʯ��֮��ÿһ�������Ͷ�������ͬ ,�����������������õ�������\n"
          "������˽⵽��Щʯ��Ĵ�������һ���������ʮ�־�ͨ���� ,������ì��\n"
          "��ذ������ ,ÿ��ʯ�����õ�������������ͬ .��ʱ�㲻������������ ,��\n"
          "Щʯ��������ﵽ��������Ŀ���� ?����ط�λ춳��еĽ��� ,��Щʯ����\n"
          "�Եز������ػ��������õ� ,Ҳ�������������͵� ,��Щʯ�����ص�������\n"
          "ʲ���� ?\n" :
          "???"
         );
   return 1;
}

string search_statue()
{
    return 
      "������ϸ����Ѱ��Щ�����ʱ�� ,�㷢���������̽� ,ذ�� ,��ì ,���� ,\n"
      "�Լ����ϵ���������ĵײ�����һ��СС��Բ�� ,�ƺ�ͨ��ĳ���ط� ,����\n"
      "��춶���ʵ����̫խ�����ƺ����� ,���޷�����������ʲ�� ?\n" ;
}

void init()
{
     add_action("to_throw","throw");
}

int compare_weapon()
{    
     mixed weapons;
     int i;
     weapons=keys(query("now_weapons"));
     for(i=0;i<sizeof(weapons);i++)
       if ( (int)query("now_weapons/"+weapons[i]) !=  (int)query("correct_weapons/"+weapons[i]) )
        return 0;
     return 1;
}

int to_throw(string str)
{
    object player,ob;
    string weapon ,type;
    int i,chinese_mode;
    
    player=this_player();
    chinese_mode=can_read_chinese(player);
    
    if ( !str || str=="") 
       return notify_fail("The Syntax: throw <weapon> to hole\n"); ;
    if ( sscanf(str, "%s to hole", weapon) == 1 )
	   {
       ob=present(weapon,player);
       if(!ob)
	     return notify_fail( chinese_mode?
			"������û������������\n":
			"You don't have that on you.\n"); 
       if( ob->query("prevent_drop") || ob->query("secure") )
 		 return notify_fail( chinese_mode?
 			"��û�а취����������\n":
 			"You can't drop that object.\n");       
       type =ob->query("type");
       if (  undefinedp( query("now_weapons/"+type) )  )
             return notify_fail(chinese_mode?"Error\n":"Error\n");
       tell_object(player,chinese_mode? "OK\n":"OK\n");
       ob->remove();
       i=(int)query("now_weapons/"+type) ;
       set("now_weapons/"+type,i?0:1);
       if ( (int)query("now_weapons/"+type) ==(int) query("correct_weapons/"+type) )
          {
          write("�������Ӷ��д���һ������ ......Ding......\n");
          if ( compare_weapon() ) {
            this_player()->move_player(Deathland"/ruin1/down01",
            ({"","","%s go here.\n","%s �������������.\n"}),"");
            write("���Ȼ�ص���һ����������.\n");
            }
          }
       else 
          write("�������Ӷ��д���һ������ ......Dong......\n");
       
       return 1;
       }
    else 
      return notify_fail("The Syntax: throw <weapon> to hole\n"); 
}

void set_correct_weapons()
{
     set("correct_weapons/longblade",random(2)); 
     set("correct_weapons/shortblade",random(2)); 
     set("correct_weapons/dagger",random(2)); 
     set("correct_weapons/chain",random(2)); 
     set("correct_weapons/thrusting",random(2)); 
     return;
}


void reset()
{
     ::reset();
     set_correct_weapons();
     set( "direction" , random(3) );
     
}
