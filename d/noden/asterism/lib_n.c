// File: /d/noden/asterism/lib_n.c

#include "asterism.h"

inherit ROOM;

void create()
{
	::create();
	set_short("storage room", "������");
	set_long( @LONG_DESCRIPTION
LONG_DESCRIPTION
		,@C_LONG_DESCRIPTION
�����ǰ�˹���ɶ��ǵ�ͼ��ݲ����ҡ���ħ��ս����������ͼ��ݲ��鼸����ȫ
�ݻٴ������ؾ���ս�����ҵ������вб�ȫ�ռ������һ�����������������
������ǽ�ߡ�һ������ǽ�ϵ������ο��������� "��Ȼ��" �� 
C_LONG_DESCRIPTION
	);
 
//	set_outside( "asterism" );
	set( "light", 1 );
        set("c_item_desc",([
            "shelves":
             "�����Ϸ���һ�ѶѸ��������ľ��ᣬ����޹���չ����顣Ҳ�������һ�\n"
             "��Щ�ջ�\n" ,
            "shelf":
             "�����Ϸ���һ�ѶѸ��������ľ��ᣬ����޹���չ����顣Ҳ�������һ�\n"
             "��Щ�ջ�\n" , 
             ]));       
	set( "exits", ([ 
		"south":ASTR"lib01"
		]) );
	reset();
	
}                         

void init()
{
       add_action("do_search","search") ;
       add_action("do_read","read") ;
}

int do_search(string s)
{
    int checkflag ;
    
    checkflag = this_player()->query_temp("check_n_lib") ;
    
    if ( !s || !(s=="shelves"|| s=="shelf"))
        return notify_fail(can_read_chinese()?
          "��Ҫ��ʲ�᣿\n" : "What are you looking for ?\n"  ) ;
         
    if ( !checkflag || checkflag != 1 )
       { 
         write(can_read_chinese()?
           "����Ŀ¼�ҵ��˼�������ø���Ȥ���飬���Ƿֱ���:\n"
           " 1. ��Ȼ��Ĺ���\n"   
           " 2. ����â������\n"
           " 3. ��Ȼ���ѭ��\n"  :
           ""  )  ;
         this_player()->set_temp("check_n_lib",1) ;
         return 1;
       }
       
    else 
       { 
         write(can_read_chinese()? 
          "����˸ոյ���Щ���⣬��Ҳ�Ҳ���������Ȥ���ˡ�\n":
          "" ) ; 
         return 1 ;
       }      
}

int do_read(string s)
{
    int checkflaga,no ;
    object obj ;
    string str ;
    
    checkflaga = this_player()->query_temp("check_n_lib") ;
    
    if ( !checkflaga || checkflaga != 1 )
         return notify_fail(can_read_chinese()?   
           "�㲻֪����Ҫ��ʲ�ᡣ\n" : "You don't know what do you wanna do.\n "
              ) ;                       
                     
    if ( !s )
      return notify_fail(can_read_chinese()?
             "��Ҫ��ʲ�ᶫ����\n" : "What do u wanna read ?\n" ) ;
    
    if(s=="1") no =1 ;
    if(s=="2") no =2 ;
    if(s=="3") no =3 ;

    if(!(!no))
      {      
        switch(no)
          {
             case(1) : str="elem" ;
                      break ;
          
             case(2) : str="pentagram" ;
                      break ;
          
             case(3) : str="cycle" ;
                      break ;
                    
            }    
        this_player()->more(BOOKS+str,0,1) ;    
        return 1 ;                 
       }
   return notify_fail(can_read_chinese()?
             "����Ҫ��ʲ�ᶫ����\n" : "What do u wanna read ?\n" ) ;

}   



