<%@ page contentType="text/html; charset=utf-8"%>
<%@ page import="java.sql.*"%>
<%@ page import="java.io.*"%>
<%@ page import="java.util.ArrayList"%>

<html>
<head>
<title>Result</title>
<link rel="stylesheet" href="./resources/css/bootstrap.min.css" />
<script src="./resources/js/map2.js"></script>
<script src="./resources/js/jquery-3.6.0.min.js"></script>
</head>

<body>
	<div style="width: 90%; margin: auto">
		<h1>Test Result</h1>
		<table class="table table-hover table-bordered">
			<thead>
				<tr bgcolor="skyblue" align="center">
					<th>이미지</th>
					<th>삭제</th>
				</tr>
			</thead>
			<tbody>

				<%@ include file="dbconn.jsp"%>
				<%
				String dectect = request.getParameter("dectect");
				System.out.println(dectect);
				
				if("ok".equals(dectect))
				{
					// System.out.println("ok of ok");
					// 킥보드가 검출된후 
					// 안드로이드 에서 gps 정보를 가져오는 코드
				}
				
				PreparedStatement pstmt = null;
				ResultSet rs = null;
				String sql = "select * from result";
				pstmt = conn.prepareStatement(sql);
				rs = pstmt.executeQuery();
				while (rs.next()) {
				%>
				<tr align="center">
					<td style="width: 30%"><img src="./resources/images/<%=rs.getString("r_id")%>.png"
						style="width: 100%"></td>
					<td style="width: 20%"><a
						href="./deleteResult.jsp?r_id=<%=rs.getString("r_id")%>"
						class="btn btn-danger" role="button">삭제</a></td>
				</tr>
				<%
				}
				if (rs != null)
				rs.close();
				if (pstmt != null)
				pstmt.close();
				if (conn != null)
				conn.close();
				%>
			</tbody>
		</table>


		<footer class="container">
			<p>&copy; 2021 Capstone</p>
		</footer>
</body>
</html>