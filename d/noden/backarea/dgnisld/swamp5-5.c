#include "dgnisld.h"

inherit ROOM;

int  steps;
int  lights;
int  balls;
int  rdm;

void create()
{
	::create();
	steps = 1;
	lights = 1;
	balls = 1;
	rdm = 9;
	set( "light" , 1 ) ;
	set( "dig", 1 );
	set_short( "cellar",  "�ض�" );
	set_long(
	    "A cellar under the swamp. You feel watery here. You can see\n"
	"a stair made of mire, it looks weak to load anyone. To the west\n"
	"you can see something under the wall. There has a fetor here, so\n"
	"you feel very ailing now. But it's queer in around. There is a \n"
	"torch on the wall near the stair.\n",
	    "�����µĵض�������ʮ�ֵس�ʪ��������һ��������(mire)�����\n"
        "¥��(stair) �����ߵ�ǽ(wall)�����ж�������������������һ�ɴ̱�\n"
        "�Ķ��������е���������£���Χ(around)�����˿��ɵ����ա�����\n"
        "¥�ݵ�ǽ����һ�ѻ��(torch)��\n" );
        
        set( "item_func", ([ "around" : "msg_around" ,
                             "wall"   : "msg_wall",
                             "stair"  : "msg_stair",
                             "mire"   : "msg_mire",
                             "torch"  : "msg_torch",    ]) );
                             
        set( "exits", ([  "up" : DGNISLD"swamp5-6",  ]) );
        set( "pre_exit_func", ([
                 "up"  : "to_up" ,    ])  );
}

void init()
{
       add_action("light_on_off"  , "light" );
       add_action("enter_hole", "enter" );
}

int to_up()
{
       object  obj;
       
       obj= present( "dragon ball", this_player() );
       if (( obj!=0) && ( (int)obj->query("dgnball")==1 )) {
         write( !can_read_chinese() ?
           "A magic power stop you to climb up!!\n":
           "ͻȻ��һ��������ֹ������ȥ��\n");
         return 1;
       }
       else {
         write("You climd up the stair and go up.\n");
         return 0;
       }
}

int to_find_dig(string str)
{
       object obj;
       int chinese_mode;
       chinese_mode = can_read_chinese();
       
       if ( (str!="mire") || (steps<4) )
         write("You can't dig it!\n");
       else if ( (steps>3) && (steps<rdm) ) {
         write( !chinese_mode ?
           "You dig a lot of time, and you feel tired.\n":
           "������һ������е�ƣ�롣\n");
          steps++;
       }
       else if ( (steps>(rdm-1)) && (balls==1) ) {
         write ( !chinese_mode ?
           "You dig and dig, finnally you find a light ball!\n"
           "But there appear someone and take it away.\n":
           "��һ�����ڣ�������춷�����һ�Żᷢ�����\n"
           "����ͻȻ����һ���˰��������ˡ�\n");
         obj = new(DGNISLD"monster/dgnbgrd.c");
         obj->move(this_object());
         balls = 0 ;
       }
       else write( !chinese_mode ?
            "You find nothing in there! :( \n" :
            "�㷢�����澹�ǿյģ��׷������ˡ�:( \n");
       return 1;     
}

int light_on_off(string str)
{
       int chinese_mode;
       chinese_mode = can_read_chinese();
       
       if (str=="off torch") {
         if (lights==1) {
           write( !chinese_mode ?
             "The torch is dead again.\n":"���Ļ�Ϩ���ˡ�\n");
           lights = 0;
           set ("light" ,0);
         }
         else write( !chinese_mode ?
           "The torch is not burning!\n":"�����Ϩ��ġ�\n");  
         return 1;
       }     
       else if (str=="on torch") {
         if (lights==0) {
           write( !can_read_chinese() ?
                "The torch becomes burning.\n" :
                "��濪ʼȼ�գ�����������ž����������\n");
           lights = 1;
           set("light" ,1);
         }
         else 
           write( !chinese_mode ?
             "The torch is burning!\n":"����Ѿ���ȼ�յġ�\n");
         return 1;
       }  
       else 
         return 0;
}

int msg_around()
{
        int chinese_mode;
        chinese_mode = can_read_chinese();
        
        if (lights==1) {
          if (balls==1) write( !chinese_mode ?
            "There are a little light in around, it is so potty\n"
            "that you almost can't tell it form the one of your\n"
            "torch. Because ligtht of torch is too strong!\n":
            "���ƺ�����һ�ɺ�΢���Ĺ�����һ����������춻��̫���ˣ�\n"                                   
            "���޷��ֱ�������Ķ�����\n");
          else write( !chinese_mode ?
            "This place is very dusty, you find nothing special here.\n":
            "��ط������ң��㲢û���ҵ��κ��ر�Ķ�����\n");
        }
        else {
          if (balls==1) {
            steps = 2 ;
            write( !chinese_mode ?
              "In the dark, you see a potty light from the stair.\n":
              "�ںڰ����㷢��һ��������¥�ݷ��������\n" );
          } else write( !chinese_mode ?
            "You feel more dark now, but still nothing special.\n":
            "��������ڱȽϰ��ˣ�����Ȼû���ҵ��κ��ر�Ķ�����\n");
        }  
        return 1;  
}

int msg_stair()
{
        int chinese_mode;
        chinese_mode = can_read_chinese();
        
        if ( (steps>1) && (lights==0) && (balls==1) ) {
          write( !chinese_mode ?
            "You canvass it and find the light is comimg from the\n"
            "mire near middle of the stair.\n":
            "����ϸ����¥�ݣ����ֹ��¥�ݼ����������������\n");
          steps = 3;
        }
        else write( !chinese_mode ?
            "It is a normal stair and made by mire.\n"
            "You find nothing special on it.\n":
            "���������ѳɵ�¥�ݣ�û�����ر�ġ�\n");
        return 1;
}

int msg_mire()
{
        int chinese_mode;
        chinese_mode = can_read_chinese();
        
        if (steps>(rdm-1))
          write( !chinese_mode ?
            "The mire has been digged deeply!\n":"�����ڵ����߰��㡣\n");
        else if ( (steps>4) && (steps<rdm) )
          write( !chinese_mode ?
            "The mire has been a little digged!\n":"�����ڵ�һЩ��\n");
        else if ( (steps<5) && (steps>2) && (lights==0) ) {
          write( !chinese_mode ?
            "There is some potty light transude in it.\n":
            "��΢���Ĺ��ߴ�������������\n");
          steps = 4;
          rdm = 6 + random(4) ;
        }
        else write( !chinese_mode ?
            "It's dusty, the ingredient of this stair.\n":
            "�������������¥�ݵ���Ҫ���ϡ�\n");
        return 1;  
}

int msg_wall()
{
       int x;
       int chinese_mode;
       chinese_mode = can_read_chinese();
       x=(int)(DGNISLD"entrance.c"->get_cropps());

       if (x==0)
         write( !chinese_mode ?
           "It is a mired wall.\n":"������ͨ����ǽ��\n");  
       else if (x==1)
         write( !chinese_mode ?
           "You see a small hole which can let only one person enter\n"
           "and looks like very weak. You can type hole to enter.\n":
           "�㿴��һ��С������С��һ��ֻ����һ��ͨ��(enter)��\n"
           "��������ΣΣ��׹��������ʱ���������\n");         
       else write( !chinese_mode ?
           "You find a small hole, but it's broken.\n":
           "���ҵ�һ��С������ϧ�ⶴ�Ѿ����ˣ�\n");  
       return 1;                            
}

int msg_torch()
{
       int chinese_mode;
       chinese_mode = can_read_chinese();
       
       if ( lights == 1 )
         write( !chinese_mode ?
           "The torch is burning, you can light off it.\n":
           "���Ļ��������ܵ�ȼ�����������Ϩ��(light off) ����\n");
       else
         write( !chinese_mode ?
           "The torch is not light, you can light on it.\n":
           "��氲�������ز���ǽ�ϡ�����Ե�ȼ(light on) ����\n"); 
       return 1;
}

int enter_hole(string str)
{
      int x;
      
      x = (int)(DGNISLD"entrance.c"->get_cropps());
      if( (!str) || (str=="") )
        return notify_fail("Enter what ?\n");
      if( (str!="hole") || (x==0) )
        return notify_fail( !can_read_chinese()?
          "There is no "+str+" here !\n":"����û��"+str+"��\n");  
      else if (x==1)
        this_player()->move_player(DGNISLD"entrance", "", "enter hole") ;
      else if (x==2) 
        write( !can_read_chinese() ?
          "The hole is broken, you can't enter it!\n":
          "�ⶴ�Ѿ����ˣ����޷����룡\n");
      else 
        write("What?\n");
      return 1;    
}                    

void reset()
{
      ::reset();
      steps = 1;
      lights = 1;
      balls = 1;
      rdm = 9;
}
