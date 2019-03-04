#include <mudlib.h>

inherit OBJECT;

void create()
{
	set_short("@@query_c_name");    
        
        set("c_realname","����");         // ��ұ��ϳɹ����ص�����
        set("realname","yellow lotus");
	
   	set("unit","��");                     // ��,��,��.�����

   	set("weight", 50000);                 // ֻҪ��֤��Ұ᲻���ͺ���

   	set("value", ({0, "silver"}) );       // Ұ��������Ȼ��ֵǮ��
      
        set("herb_file","yellow_lotus.c") ;     //���������Ķ�������������
        set("herb_path","/d/healer/reagent/");   //���������Ķ�����Ŀ¼
                                              //�ǵ�������Ŀ¼
                                              //default �� /d/healer/plant
                                                
        set("skill_require",45) ;             //Ҫ�ɹ���ʶ����ֲ������֮����
        set("purified",3);                    //�Ƿ񱻱��˽����ȵ�,0Ϊ��,1Ϊ��
       
        set("plant_type",0);                  //

}

string query_c_name()
{
  string* verified;
  string temp;
  string s;
  int i;
  int ok;
  
  if ( this_player()->query_temp("last_verify") ){
    verified=explode(this_player()->query_temp("last_verify"),"\n");
    ok = 0;
    sscanf(identify(this_object() ),"%s/%s",s,temp);
    for ( i = 0 ; i < sizeof(verified) ; i ++) {
      if ( (verified[i]) == temp )
        ok=1;
    }
  }
  else ok = 0;

  if (this_player()->query_stat("int") < 10 ) {
    set("id",({"plant","tree"}) );
    set_name("a plant","ˮ��ֲ��");
    set_long("����ˮ��ֲ�����κ�һ����ƺ���Щ��ͬ, ��ϧ����򵥵�С�Դ���,\n"
             "����˵��������Ȼ����\n");
    return "ˮ��ֲ��";
  }
  else if ( ok==1 ) {
    set("id",({"plant","tree","lotus","yellow lotus"}) );
    set_name("lotus","����");
    set_long("��������ϸ�����Ľ��, ���ж�����һ������,�����Ŀ�������(yellow lotus),\n"
             "�������ҩ��, ��������(dig)һ���ȥ��\n");
    return "����";
  }
  else {
    set("id",({"plant","tree"}) );
    set_name("a plant","ˮ��ֲ��");
    set_long("���ˮ��ֲ�ﲢ���ձ�, Ҫ��֪����ȷ�������һ���ļ�����\n");         
    return "ˮ��ֲ��";
  }
}      
