package hitoan.me.cookie;

import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.Cookie;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

@WebServlet(urlPatterns = "/servlet2")
public class Servlet2 extends HttpServlet{
	@Override
	protected void doGet(HttpServletRequest req, HttpServletResponse resp) 
			throws ServletException, IOException {
		resp.setContentType("text/html");
		PrintWriter out = resp.getWriter();
		out.println("Da lay cookie thanh cong!");
		
		Cookie[] cookies = req.getCookies();
		
		for (Cookie c : cookies) {
			out.println(c.getName() + " : " + c.getValue() + "<br>");
			
			if (c.getName().equals("age")) {
				out.println("Da tim thay cookie username: " + c.getValue());	
				c.setMaxAge(0);
				
				resp.addCookie(c);
			}
		}
	}
}
