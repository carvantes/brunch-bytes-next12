// pages/hello.js

const HelloPage = ({ message }) => {
  return (
    <div>
      <h1>{message}</h1>
    </div>
  );
};

export async function getStaticProps() {
  // This function runs at build time
  return {
    props: {
      message: 'Hello, world!',
    },
  };
}

export default HelloPage;