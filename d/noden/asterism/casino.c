// This is casino of asterism  by  Indra on 94.10.9
// File: /d/noden/asterism/casino.c

#include "asterism.h"

inherit ROOM;
inherit "gamble.c" ;

void create()
{
	::create();
	set_short("A Casino", "�˿˾��ֲ�");
	set_long( @LONG_DESCRIPTION
LONG_DESCRIPTION
		,@C_LONG_DESCRIPTION
�����ǰ�˹���ɶ�(asterism)���������Ķĳ�����˹���ɶ���ս����,���
�����ͨ������,ʹ��������ܼ�Ѹ�ٵ��ɷ������ؽ�������Ͼ֮��,������ϲ��
���ƹ�С�ü�С��һ������֮,�Ƶ��ϰ�Ǭ�������ģ,����ĳ����ˡ�
�������������,�������(Poker)��̨��,������Ǳ�21��(Black Jack)�ĳ���,
���ұ���������(Dice)�ĵط�����������ǰ���Ƕ�ǽ���ƺ����Ź���(rule)��
��һ���淨˵��(explain)��
C_LONG_DESCRIPTION
	);

	set( "light", 1 );
	set( "exits", ([ 
		"north" : ASTR"city21",
		]) );
 	set("pre_exit_func",([ "north" : "check_gamble" ]) ) ;
        set("c_item_desc",(["rule":"1.��ֹ���ס�\n"
                                   "2.��ֹ͵�ԡ�\n"
                                   "3.��ֹǿ�ᡣ\nΥ��һ����˽���ź�\n",
                            "explain":
                                   "" ,
                            ]) ) ;        
	reset();
}

void init()
{
   add_action("do_gamble" , "play");
   add_action("do_draw","leave");
}

int poker()
{
     this_player()->set_temp("astr_gamble/poker",1); 



     return 1 ;
}

int jack()
{
     this_player()->set_temp("astr_gamble/jack",1);

      
     return 1 ;
}

int dice()
{
     this_player()->set_temp("astr_gamble/dice",1); 


     return 1 ;
}

int do_gamble(string arg)
{
    int i,j ;
    string game,cgame,msg,cmsg,mas1,cmsg1 ;
    
    if(!arg) return notify_fail(can_read_chinese()?
                   "��ɶ��Ⱑ ??\n":"What do u wanna play?\n");
                         
//    if(lower_case(arg)=="poker")    ;
//    if(lower_case(arg)=="black jack")   ;
//    if(lower_case(arg)=="dice")   ;            
//    else return notify_fail(can_read_chinese()?
//                   "��ɶ��Ⱑ ??\n":"What do u wanna play?\n");
                   
    switch(lower_case(arg))                   
     {  
       case "poker" :
                 game = "Poker" ;
                 cgame= "���" ;
                 play_game(game,cgame) ;
                 poker() ;
                 break ;
       case "black jack":
                 game = "Black Jack" ;
                 cgame= "��ʮһ��" ;
                 play_game(game,cgame) ;
                 jack() ; 
                 break ;
       case "dice" :
                 game = "Taiwan Dice" ;
                 cgame= "������" ;
                 play_game(game,cgame) ;
                 dice() ;
                 break ;
       default: return notify_fail(can_read_chinese()?
                  "��Ǹ,���ĳ����ṩ�����淨��\n":"Which kind do u wanna play?\n");
                break ;
      }
    
                  
    return 1 ;               
}

