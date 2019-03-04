//   This is control center to control the asterism sewer.
//             Indra@ Eastern_Story   5/9/95
//

#include "../asterism.h"

inherit ROOM ;

int reset_flag = 0 ;
int slate_flag = 0 ;

string *ROOM_INDEX = ({ "null","null","null","null", }) ;
string *SLATE_DESC = ({ "test 1\n" ,
                        "test 2\n" ,
                        "test 3\n" ,
                        "test 4\n" , }) ;
string *TRASH_DESC = ({ "trash mes1\n" , "trash msg2\n" ,}) ;

void create()
{
      ::create() ;
      set_short("��ˮ�����ܿ�����") ;
      set_long("�ⲻ�Ǹ�����ܵ���Ӧ�õ��ĵط�,�����������,����wizard���档\n") ;
      set("light",0) ;
    
      reset() ;
}

void reset()
{
      ::reset() ;
      if(reset_flag < 3 ) reset_flag++ ;
      if(reset_flag == 3)
         {
            reset_flag = 0 ;   
            slate_flag = 0 ;
            ROOM_INDEX = ({ "null","null","null","null", }) ;  
          }
      return ;
}

string slate_desc(object person,object room)
{
      int no,flag,size,index ;
      string name ;
      
      size = sizeof(ROOM_INDEX) ;
      name = file_name(room) ;
      no = member_array(name,ROOM_INDEX,1) ;
      
      if( no!=-1 )  return SLATE_DESC[no] ;
      
      if(slate_flag < size )
         {
             while(1)
                {
                   no = random(size) ;
                   if(ROOM_INDEX[no]=="null") break ;
                }
             slate_flag++ ;
             ROOM_INDEX[no] = name ; 
             return  SLATE_DESC[no];     
          }
      else
         {
            no = random(sizeof(TRASH_DESC)) ;
            return TRASH_DESC[no] ;
          }

}



