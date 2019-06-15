import java.io.IOException;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Set;

import org.jsoup.Connection;
import org.jsoup.Jsoup;
import org.jsoup.nodes.Document;
import org.jsoup.nodes.Element;
import org.jsoup.select.Elements;

public class Crawler {
	private Set<String> vizit = new HashSet<>();          //krijoj nje hashset qe do te permbaje linket e vizituara
	private Queue<String> paVizit = new LinkedList<>();   //krijoj nje radhe qe do te permbaje linket e pavizituara
	private Queue<String> tmp = new LinkedList<>();       //krijoj nje radhe qe do me ndihmoje ne vizitimin e linkeve te pavizituara

	private static final String USER_AGENT = "Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/535.1 (KHTML, like Gecko) Chrome/13.0.782.112 Safari/535.1";

	public Crawler(String URL) {
		paVizit.add(URL);            //fillimisht shtoj tek linket e pavizituara linkun fillestar

	}

	public void crawl() {
		while (!paVizit.isEmpty()) {
			String a = paVizit.remove();               //bej hkalimin nga linket e pavizituara tek linket e vizituara 
			tmp.add(a);                                // deri s ate mos kete me linke tek radha e linkeve te pavizituara   
		}

		while (!tmp.isEmpty()) {
			String b = tmp.remove();            //marr elementin e pare qe kam per te vizituar
			if (vizit.contains(b))             // nqs e kam vizituar nje here vazhdoj me elementin tjt ne radhe
				continue;

			try {
				Connection connection = Jsoup.connect(b).userAgent(USER_AGENT).ignoreContentType(true);
				Document htmlDocument = connection.get();            //krijoj objektin dom te faqes html qe po vizitoj

				Elements linksOnPage = htmlDocument.select("a[href]");    //marr te gjitha elementet qe fillojn me atributin ankor href
				for (Element link : linksOnPage) {
					if (link.absUrl("href").length() == 0)
						continue;
					this.paVizit.add(link.absUrl("href"));         //linqet qe i gjej i vendos tek radha e linkeve te pavizituara
				}
				vizit.add(b);               //pasi kam mbaruar e shtoj linkun qe po vizitoja te linket e vizituara 
				System.out.println(b);
			} catch (IOException ioe) {
				System.out.println("error " + ioe);   //ne rast gabimi printoj gabimin

			}
		}
	}

	/*------Metoda setters dhe getters per te marre radhat-------*/
	
	public Set<String> getVizit() {
		return vizit; 
	}

	public void setVizit(Set<String> vizit) {
		this.vizit = vizit;
	}

	public Queue<String> getPaVizit() {
		return paVizit;
	}

	public void setPaVizit(Queue<String> paVizit) {
		this.paVizit = paVizit;
	}

	public Queue<String> getTmp() {
		return tmp;
	}

	public void setTmp(Queue<String> tmp) {
		this.tmp = tmp;
	}

}
