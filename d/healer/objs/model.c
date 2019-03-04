// model.c ����������, һ��������ϰ���, ��һ�����صĹ�������
// ����Ұ��������, ÿ��model update ʱ, �����ֵ�function �ͻ�
// �Զ������е�////#pragma save_binary
#include <mudlib.h>
#include "/d/healer/healer.h"
inherit OBJECT ;

// plant.dat ������¼�ڸ��ֵ��͸ó�������ֲ��, �Լ����ֵĻ��ʱ�
#define PLANTDATA "/d/healer/plant/plant.dat"
mapping P0,P1,F0,B0,S0,H0,R0,R1;

//  ��������֮ǰ, �Ƚ��ϴ������������, ����update ������, ����
//  ������, ���ĳ���
//  kill_plant accept a argument, which is the tree's file
//  eg: kill_plant("/d/healer/plant/dang_guei_tree.c");
int kill_plant(string str) {
   object target;
   mixed *clones;
   string para, hold, tmp1, tmp2;
   int loop, dest, view, More, original;
 
   target = get_object( str );
 
   //	Oh well, couldn't find the object
 
   if(!target) return 1; 
 
   //	Try to located all copies of the object
   clones = children( file_name(target) );
   //	Its either the Master object or has no other copies around
   if(sizeof(clones) == 1) {
        tell_room(environment(target),"�㷢��"+target->query("c_name")+
                                      "������ǰ��ή�����ˡ�\n");
	target->remove();
	if(target)  destruct(target);
        return 1; 
   }
   else clones -= ({ target });
 
   //	Try to remove all clone copies
   for ( loop= 0; loop<sizeof(clones); loop++){
     tell_room(environment(clones[loop]),
               "�㷢��"+clones[loop]->query("c_name")+
               "������ǰ��ή�����ˡ�\n");
     clones[loop]->remove();
   } 
   clones = children( file_name(target) );
   clones -= ({ target });
   //	If there are any copies left...this should get rid of them
   for(loop=0; loop<sizeof(clones); loop++)
	destruct( clones[loop] );
   return 1; 
}

// This function plants a plant in a specified room
void make_plant (string room, string the_plant)
{
  object this_room;
  object this_plant;
  
  this_plant=new(the_plant);
  this_room=find_object(room);
  if ( this_room && this_plant) this_plant->move(this_room);
}  

// choose_plant accept 2 arguments, the first is the 
// file name of a room, the second is the type of the room
// for example, P0 means ƽԭ
// choose_plant ����room_type, ������Ƿ�ó���, �Լ��ó�
// ʲ������, ���� make_plant�ڸ÷�������
void choose_plant(string room, string room_type)
{
  int i;
  int max;
  int decision;
  
  switch (room_type) {
    // P0 is ƽԭ , have 1/8 chance to have a plant
    case "P0" : max=P0[sizeof(P0)-1][0]*8;
                decision=random(max);
                for ( i = 0 ; i < sizeof(P0) ; i++ ) 
                  if (decision<P0[i][0]) { make_plant(room,P0[i][1]);
                                           return;
                                         }
                break;                           
     // P1 is �ӱ�, have 1/8 chance to have a plant           
    case "P1" : max=P1[sizeof(P1)-1][0]*8;
                decision=random(max);
                for ( i = 0 ; i < sizeof(P1) ; i++ ) 
                  if (decision<P1[i][0]) { make_plant(room,P1[i][1]);
                                           return;
                                         }
                break;  
     // F0 is ɭ��, have 1/10 chance to have a plant           
    case "F0" : max=F0[sizeof(F0)-1][0]*10;
                decision=random(max);
                for ( i = 0 ; i < sizeof(F0) ; i++ ) 
                  if (decision<F0[i][0]) { make_plant(room,F0[i][1]);
                                           return;
                                         }
                break;                           
     // B0 is �ݵ�, have 1/7 chance to have a plant           
    case "B0" : max=B0[sizeof(B0)-1][0]*7;
                decision=random(max);
                for ( i = 0 ; i < sizeof(B0) ; i++ ) 
                  if (decision<B0[i][0]) { make_plant(room,B0[i][1]);
                                           return;
                                         }
                break;  
     // S0 is swamp, have 1/7 chance to have a plant           
    case "S0" : max=S0[sizeof(S0)-1][0]*7;
                decision=random(max);
                for ( i = 0 ; i < sizeof(S0) ; i++ ) 
                  if (decision<S0[i][0]) { make_plant(room,S0[i][1]);
                                           return;
                                         }
                break;                           
     // H0 is Hill, have 1/10 chance to have a plant           
    case "H0" : max=H0[sizeof(H0)-1][0]*10;
                decision=random(max);
                for ( i = 0 ; i < sizeof(H0) ; i++ ) 
                  if (decision<H0[i][0]) { make_plant(room,H0[i][1]);
                                           return;
                                         }
                break;  
     // R1 and R0 are both road, have only 1/15 chance to have a plant           
    case "R1" : max=R1[sizeof(R1)-1][0]*15;
                decision=random(max);
                for ( i = 0 ; i < sizeof(R1) ; i++ ) 
                  if (decision<R1[i][0]) { make_plant(room,R1[i][1]);
                                           return;
                                         }
                break;                           
    case "R0" : max=R0[sizeof(R0)-1][0]*15;
                decision=random(max);
                for ( i = 0 ; i < sizeof(R0) ; i++ ) 
                  if (decision<R0[i][0]) { make_plant(room,R0[i][1]);
                                           return;
                                         }
                break;
  }
}


void kill_plants()
{
  string *info;
  string area, file;
  int rate;
  int i;
  
  // read from plant data file to get all plants that 
  // maybe in ES now  
  info = explode( read_file(PLANTDATA), "\n" );
  // first, kill old plants
  for( i=0; i< sizeof(info); i++) {
    // skip comments
    if ( info[i][0]=='#') continue;
    if (sscanf(info[i],"%s:%d:%s",area,rate,file)==3) 
      kill_plant(file);
  }    
}

// plant accept an argument, indicates which map to be processed
// now only have plants on Noden and Eastland 

void plant(string map)
{
  string *info,*map_data,*temp_str;
  string area,file,name,area_file;
  int rate, i , j , k,temp,weight,height;

// initial all mapping for all 8 kinds of ���� 
  P0=([]);  P1=([]);  F0=([]);  B0=([]);
  S0=([]);  H0=([]);  R0=([]);  R1=([]);

// now.... read plants data from data file  
  info=explode( read_file(PLANTDATA), "\n" );
  for( i=0; i<sizeof(info); i++ ) {
    // Skip comments
    if( info[i][0]=='#') continue;
    if( sscanf(info[i],"%s:%d:%s",area,rate,file)==3 ) {
      switch(area) {
        case "P0": temp=sizeof(P0);if (temp>0) rate+=P0[temp-1][0];
                   P0[temp]=({rate,file});break;
        case "P1": temp=sizeof(P1);if (temp>0) rate+=P1[temp-1][0];
                   P1[temp]=({rate,file});break;
        case "F0": temp=sizeof(F0);if (temp>0) rate+=F0[temp-1][0];
                   F0[temp]=({rate,file});break;
        case "B0": temp=sizeof(B0);if (temp>0) rate+=B0[temp-1][0];
                   B0[temp]=({rate,file});break;
        case "S0": temp=sizeof(S0);if (temp>0) rate+=S0[temp-1][0];
                   S0[temp]=({rate,file});break;
        case "H0": temp=sizeof(H0);if (temp>0) rate+=H0[temp-1][0];
                   H0[temp]=({rate,file});break;
        case "R1": temp=sizeof(R1);if (temp>0) rate+=R1[temp-1][0];
                   R1[temp]=({rate,file});break;
        case "R0": temp=sizeof(R0);if (temp>0) rate+=R0[temp-1][0];
                   R0[temp]=({rate,file});break;
        default:   break;
      }   // end of switch          
    }    // end of if 
  }     // enf of for loop.... plant data read finished!

  // plant data read ok, now start to process the map
  map_data=explode( read_file(map),"\n");  
  for ( i = 0; i < sizeof (map_data); i++) {
    //skip comments
    if(map_data[i][0]=='#') continue;
    
    // get the weight and height of the map
    
    if( sscanf(map_data[i],"%s:%d%d",name,weight,height) == 3 ) {
      for ( j = 0 ; j < height ; j ++ ) {
        i++;
        temp_str=explode(map_data[i]," ");
        for ( k = 0 ; k < weight; k ++ ) {
          if (map=="/d/noden/noden.map")
          
          // get the file name from virtual map,
          // noden and eastland's file name r slightly different
          // so need to check map
            
            area_file="/d/noden/"+k+","+j+".noden";
          else
            area_file="/d/eastland/"+k+","+j+".east";
          
          // for each room, call choose_plant to decide if it should have
          // a plant, and which plant
            
          choose_plant(area_file,temp_str[k]);    
        }
      }
    }
  }
}


void create()
{
        seteuid(getuid()) ;
        set("id", ({"model","brass model"}) ) ;

	set_name("brass model", "ͭ��");
	set_short("ͭ��");
	set("long", "@@model_desc" );

	set( "unit", "��" );
	set( "weight", 1000000 );
        set("prevent_get",1);
        set("temp1",({ }) );
        set("temp2",({ }) );
        set("temp3",({ }) );        
        // call kill_plants before start to ����
        kill_plants();
        plant("/d/noden/noden.map");
        plant("/d/eastland/eastland.map");
}

void init()
{
	add_action("do_practice", "practice");
	add_action("do_exam", "exam");
}

string model_desc()
{
     int pts_no,i ;
     string msg;

     if((string)this_player()->query("class")!="healer")
       {   msg = "  һ���������۵�ľ�ƽ������, ϸ���ᷢ��������һ������С�㡣\n"
                "���⻹�к��ߺ���������Щ�㡣������������ϰ����õ�ͭ���ˡ�\n"
                "�� exam <����> ���Բ��ѷ��ֵ�����Ѩ����\n"  ;
        }        
     else     
        {      
          msg = "  һ���������۵�ľ�ƽ������, ϸ���ᷢ��������һ������С�㡣\n"
                "���⻹�к��ߺ���������Щ�㡣������������ϰ����õ�ͭ���ˡ�\n"
                "�� exam <����> ���Բ��ѷ��ֵ�����Ѩ����\n"  
                "��һ����ҽ����̤��ʦ��ʩ����ҽ����ǰ���ض�Ҫ��ͭ����������׼\n"
                "ȷ����ĵز����ܱ�����ʹ�����ơ������ҽ���⣬��ϰ(practice)\n"
                "��ͭ����ʩ�����ѧ����ĵĲ������š�\n\n" ;
        }        
     return msg ;    
}

// i : position of the name array, j : length of the array,
// temp : array of point name, first_str : name of meridians
int do_exam(string arg)
{
   int    i,j ;
   string *temp,first_str ;

   if(!arg||arg=="����") arg="title" ;
   
   temp = ALL_POINTS->query_meridians(arg) ;
   first_str = temp[0]  ; 
   if(first_str=="NULL") return 0 ;

   if(arg=="title") 
       write("����ȫ���繲��ʮ�������ֱ�Ϊ:\n") ;
   else
       write(first_str+"����Ѩ������:\n") ;   

   j = sizeof(temp);
   for(i=1;i<j;i++)
     {
        write(temp[i]) ;
        if(i!=j-1) write(", ") ;
        if((arg=="title")&&(i%5==0)) write("\n") ;
        else
         {
           if((arg!="title")&&(i%8==0)) write("\n") ;
         }
      }
    write(" ��\n") ;
    return 1 ;
}

int do_practice(string arg)
{
     int i , j , check_flag, *merid_no,difficulty,acu_skill;
     string *temp,*practiced ;
     temp      = ({ }) ;
     practiced = ({ }) ; 
     
     if((string)this_player()->query("class")!="healer")
          return notify_fail("С���� , �����ʲ�� ???\n") ;

     if(!arg)
          return notify_fail
          ("Ҫ��ϰ��ļ���, ֻҪ������ϰ(practice)<����>, �Ϳ��Դﵽ\n"
           "��ϰ��Ч����\n") ; 

     temp      = ({ arg }) ;
     acu_skill = this_player()->query_perm_skill("acupuncture") ;

     temp  = ALL_POINTS->query_meridians(arg) ;
     if(temp[0]=="NULL") 
        {
          write("û����������..\n") ;
          return 1 ;
          }

     merid_no = ALL_POINTS->query_meridians_no(arg) ;

     difficulty = merid_no[1] ;
     difficulty = difficulty * 6 + 15 ;
     j = sizeof(temp);
     for ( i = 1 ; i < j ; i ++ ) {
       write ("����������, ��ͭ�˵�"+temp[i]+"Ѩ���˽�ȥ��\n");
       tell_room(environment( this_player() ),
                 this_player()->query("c_name")+
                 "��������, ��ͭ�˵�"+temp[i]+"Ѩ���˽�ȥ��\n",
                 this_player() );
     }  
       
     if( ( acu_skill > difficulty ) || wizardp(this_player()) )     
       {
         this_player()->set("prac_meridians/"+arg,merid_no[0]) ;
         this_player()->delete_temp("practice_pts") ;
         this_player()->delete("practice_pts") ;
         
         write("����ͭ����"+arg+"��ͼ��,һ��������Ӱ����̵�\n"
               "��������Ժ���\n") ;
         tell_room( environment( this_player() ),
           this_player()->query("c_name")+"�ó�����,����ͭ�����ϵ�ĳһ������"+
           "һ��Ѩ��һ��Ѩ����������\n����һ���,ֻ��������΢Ц�ӳ�˼���ſ��ۡ�\n"
           ,this_player()  ) ;
       }
     else
        {
         this_player()->delete_temp("practice_pts") ;
         this_player()->delete("practice_pts") ;

         write("\n��...�....��.......��ͻȻ�����㱻ͭ���ϵ�ͼ��Ū�Ժ��ˡ�\n"
               "����ʶ����������Լ����ܲ���, ��Ǿ���ҪŬ��׬ EXP��\n ");

       }
     return 1 ;
}
